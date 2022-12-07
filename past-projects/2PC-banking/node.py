import json
import sys
import random
from multiprocessing.connection import Client, Listener
from multiprocessing import Lock
from threading import Thread


# NODE CONSTANTS
MY_ID = int(sys.argv[1])
PORTS = [17000, 17001, 17002]
SERVERS = [('localhost', port) for port in PORTS]
MY_ADDRESS = ('localhost',  PORTS[MY_ID-1])

if MY_ID == 1:
    print(SERVERS)

#Client Side
class RPCProxy:
    def __init__(self, connection):
        self._connection = connection

    def __getattr__(self, name):
        def do_rpc(*args, **kwargs):
            self._connection.send(json.dumps((name, args, kwargs)))
            result = json.loads(self._connection.recv())
            return result
        return do_rpc
        
#Server State Variables
#Sets the Bank Account Values in accordance with the Account A or B, and the connection info
accountAVal = ("Account A", 200, SERVERS[1])
accountBVal = ("Account B", 300, SERVERS[2])

#Server Side
class RPCHandler:
    def __init__(self):
        self._functions = { }

    def register_function(self, func):
        self._functions[func.__name__] = func

    def handle_connection(self, connection):
        try:
            while True:
                # Receive a message
                func_name, args, kwargs = json.loads(connection.recv())
                # Run the RPC and send a response
                try:
                    r = self._functions[func_name](*args,**kwargs)
                    connection.send(json.dumps(r))
                except Exception as e:
                    connection.send(json.dumps(str(e)))
        except EOFError:
             pass

#Returns the value of each account to Client A and B
def getAccountVal():
    global accountAVal, accountBVal
    print(str(accountAVal))
    print(str(accountBVal))

#Makes the file that retains all transaction info
#Starts with the addition of the set values for each account
#Makes sure to close file at the end
def makeFile():
    f = open("Account Transfers.txt", "w")
    trackChanges(accountAVal)
    trackChanges(accountBVal)
    f.close()

#Tracks the changes made to each of the accounts
#Writes the new info in the account and closes the file at the end
def trackChanges(account):
    f = open("Account Transfers.txt", "a")
    f.write(str(account) + "\n")
    f.close()

#Function that is used to subtract $100 from Account A
#Function also adds the $100 to Account B
#This effectively simulates the transference of $100 from A-->B
#Uses trackChanges to add transaction info to the file
#Subtract() will not work if Account A has less than 100 in it
#It will notify the user and prompt a different input
def subtract():
    global accountAVal, accountBVal
    
    if accountAVal[1] < 100:
        seperator = "ERROR: Account A has less than $100 and cannot go below $0"

    elif accountAVal[1] >= 100:
        seperator = "-----Move $100 from Account A to Account B-----"
        #print("In Subtract")
        aValue = accountAVal[1] - 100
        bValue = accountBVal[1] + 100

        aList = list(accountAVal)
        aList[1] = aValue
        accountA = tuple(aList)
        accountAVal = accountA

        bList = list(accountBVal)
        bList[1] = bValue
        accountB = tuple(bList)
        accountBVal = accountB

    trackChanges(seperator)
    trackChanges(accountA)
    trackChanges(accountB)
    #print("End Subtract")

#Function that calculates the 20% Bonus
#Takes the current value of Account A, and gets 20% of that value
#Adds that new value, aBonus, to both Account A, and Account B
#Uses trackChanges to add transaction info to the file
def bonus():
    global accountAVal, accountBVal
    seperator = "-----Add 20% Bonus from Account A's Post $100 Value to Accounts A and B-----"
    #print("In Bonus")
    aBonus = accountAVal[1] * 0.2

    aList = list(accountAVal)
    aList[1] = accountAVal[1] + aBonus
    accountA = tuple(aList)
    accountAVal = accountA

    bList = list(accountBVal)
    bList[1] = accountBVal[1] + aBonus
    accountB = tuple(bList)
    accountBVal = accountB
    
    trackChanges(seperator)
    trackChanges(accountA)
    trackChanges(accountB)

#Register the various functions with the handler
handler = RPCHandler()
handler.register_function(makeFile)
handler.register_function(trackChanges)
handler.register_function(subtract)
handler.register_function(bonus)
handler.register_function(getAccountVal)

socket = Listener((MY_ADDRESS))

print(f"Node-{MY_ID} running on: {socket.address}")

while True:
    client = socket.accept()
    t = Thread(target=handler.handle_connection, args=(client,))
    t.start()