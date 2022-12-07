import json
from multiprocessing.connection import Client
from threading import Thread

class RPCProxy:
    def __init__(self, connection):
        self._connection = connection
    def __getattr__(self, name):
        def do_rpc(*args, **kwargs):
            self._connection.send(json.dumps((name, args, kwargs)))
            result = json.loads(self._connection.recv())
            return result
        return do_rpc

#Defines the coordinator
#Sets up a while loop that allows for continued responses between Accounts A and B
#Using input, the user can ask for a list of commands using help, which provides
#explanations for the 2 transaction types and information regarding exiting the transaction
#The client can use 1 for the movement of $100 from Account A to B
#The client can use 2 for the bonus function to be called
def coord():
    c = Client(('localhost',17000))
    proxy = RPCProxy(c)
    proxy.makeFile()
    while True:
        inp = input('Enter Transaction Type 1 or 2: ').strip()
        if not inp:
            continue
        if inp == "1":
            reply = proxy.subtract()
        if inp == "2":
            reply = proxy.bonus()
        if inp == "help" or inp == "Help":
            print("Use 1 to move $100 from Account A to B")
            print("Use 2 to add a 20% bonus of Account A's current value to itself and Account B")
            print("Use Exit to end the transaction")
        if inp == "Exit" or inp == "exit":
            print("Ending Transaction")
            break
    print(reply)

#Defines Account A, which receives updated information regarding the accounts
def accountA():
    c = Client(('localhost',17001))
    proxy = RPCProxy(c)
    reply = proxy.getAccountVal()
    print(reply)

#Defines Account B, which receives updated information regarding the accounts
def accountB():
    c = Client(('localhost',17002))
    proxy = RPCProxy(c)
    reply = proxy.getAccountVal()
    print(reply)
    
t1 = Thread(target=coord)

t1.start()