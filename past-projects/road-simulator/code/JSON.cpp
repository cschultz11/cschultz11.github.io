#include "JSON.h"
#include "Map.h"
#include "Road.h"
#include "roadItem.h"

#include <vector>
#include <iostream>
#include <stdio.h>

void JSONSave::SaveMap(Map *map, ostream& stream)
{
	stream << "{" << endl;
	stream << "\"Roads\":";
	stream << "[" << endl;
	vector<Road*> roads = map->GetRoad();

	int i = 0;
	for (Road* road : roads) {
		road->Save(this, stream);
		if(i != roads.size()-1)
			{
			stream << ",";
			i++;
			}
	stream << endl;
	}
	stream << "]" << endl;
	stream << "}";
}

void JSONSave::SaveRoad(Road *road, ostream& stream)
{
	RoadItem ri;
	int hdg;
	hdg = (int)road->GetHeading();
	stream << "{" << endl;
	stream << "\"Name\":\"" << road->GetRoadName() << "\"," << endl;
	stream << "\"Length\":" << road->GetLength() << "," << endl;
	stream << "\"XLocation\":" << road->GetXLocation() << "," << endl;
	stream << "\"YLocation\":" << road->GetYLocation() << "," << endl;
	stream << "\"Heading\":" << hdg << "," << endl;
	stream << "\"RoadItems\":[" << hdg << "," << endl;
	stream << "}";

	return;
}

void JSONSave::SaveStopSign(StopSign* roadItem, ostream& stream)
{
	stream << "\"Type\":" << roadItem;
	stream << "\"MileMarker\":" << roadItem->getMM();
}

void JSONSave::SaveSpeedLimit(SpeedLimit* roadItem, ostream& stream)
{
	stream << "\"Type\":" << roadItem;
	stream << "\"MileMarker\":" << roadItem->getMM();
	stream << "\"SpeedLimit\":" << roadItem->getSpeedLimit();
}


void JSONLoad::LoadMap(Map *map, istream& stream)
{
	string identifier;
	char symbol, tempSym;

	getline(stream, identifier);
	symbol = identifier[0];
	if (symbol != '{')
		{
			return;
		}

	do {

		identifier = "";
		getline(stream, identifier);
		if(identifier.find('[') != string::npos)
		{
			tempSym = '[';
		}
		symbol = identifier[identifier.size()-2];
		if (symbol != ':')
		{
			return;
		}
		identifier.pop_back();
		identifier = identifier.substr(1,identifier.size()-3);
		if (identifier == "Roads")
		{
			symbol = tempSym;
			if (symbol != '[')
			{
				return;
			}
			do
			{
				Road* r = new Road();
				r->Load(this, stream);
				cout << "LOADED"  << endl;
				map->AddRoad(r);
				getline(stream, identifier);
				symbol = identifier[1];

//				RoadItem* ri = new RoadItem();

			} while (symbol == ',');
		}
		getline(stream, identifier);
		symbol = identifier[identifier.size()-1];

	} while (symbol == ',');
	if (symbol != '}') return;
}

void JSONLoad::LoadRoad(Road *road, istream& stream)
{
	string identifier, roadName;
	double xLocation, yLocation, length;
	Heading heading;
	char symbol;

	getline(stream, identifier);
	symbol = identifier[identifier.size()-1];
	if (symbol != '{')
		{
			return;
		}
	do {
		identifier = "";
		getline(stream, identifier, ':');
		symbol = ':';
		//else
		//{
		//	return;
		//}
		if (symbol != ':')
		{
			return;
		}
		identifier.pop_back();
		identifier = identifier.substr(1,identifier.size()-1);
		if (identifier == "Name")
		{
			getline(stream, roadName);
			//cout << symbol << endl;
			roadName.pop_back();
			//cout << roadName << endl;
			roadName = roadName.substr(1,roadName.size()-2);
			cout << roadName << endl;
			symbol = ',';
		}
		else if (identifier == "Length")
		{

			string temp;
			getline(stream, temp);
			cout << temp << endl;
			temp.pop_back();
			length = stod(temp);
			symbol = ',';
		}
		else if (identifier == "XLocation")
		{
			string temp;
			getline(stream, temp);
			cout << temp << endl;
			temp.pop_back();
			xLocation = stod(temp);
			symbol = ',';
		}
		else if (identifier == "YLocation")
		{
			string temp;
			getline(stream, temp);
			cout << temp << endl;
			temp.pop_back();
			yLocation = stod(temp);
			symbol = ',';

		}
		else if (identifier == "Heading")
		{
			int hdg;
			string temp;
			getline(stream, temp);
			cout << temp << endl;
			hdg = stoi(temp);
			heading = (Heading)hdg;
			symbol = ',';
		}
		else if (identifier == "RoadItems")
		{
			string temp;
			getline(stream, temp);
			cout << temp << endl;
			symbol = temp[0];
			do
			{
				getline(stream, identifier);
				symbol = identifier[0];
				do
				{
					getline(stream, identifier, ':');
					cout << "ID: " << identifier << endl;
					identifier.pop_back();
					identifier = identifier.substr(1,identifier.size()-1);
					cout << "Type: " << identifier << endl;
					if(identifier == "Type")
					{
						string type;
						getline(stream, type);
						identifier = type.substr(type.size()-1, type.size());
						if(identifier != ",")
						{
							return;
						}
						symbol = ',';
						type.pop_back();
						type = type.substr(1,type.size()-2);
						if(type == "StopSign")
						{
							StopSign* stop = new StopSign();
							LoadStopSign(stop, stream);
							road->AddRoadItem(stop);
							getline(stream, identifier);
							cout << "in stop sign: " << identifier << endl;
						}
						else if(type == "SpeedLimit")
						{
							SpeedLimit* lim = new SpeedLimit();
							LoadSpeedLimit(lim, stream);
							road->AddRoadItem(lim);
							getline(stream, identifier);
							cout << "1st in speedlim: " << identifier << endl;
							getline(stream, identifier);
							cout << "2nd in speedlim: " << identifier << endl;
						}
					}
					//getline(stream, identifier);
					//cout << identifier << endl;
					//symbol = identifier[identifier.size()-1];
					//cout << symbol << endl;
					if(identifier != "},")
					{
						break;
					}
					getline(stream, identifier);
					cout << identifier << " AT END OF WHILE" << endl;
				} while (symbol == ',');
				cout << "BROKE" << endl;
				getline(stream, identifier);
				cout << "ID AT BREAK " << identifier << endl;
				symbol = identifier[identifier.size()-1];
				cout << "SYMBOL AT BREAK " << symbol << endl;
				symbol = ']';	//end RoadItems
			} while (symbol != ']');
		}

		else
		{
			return;
		}
		road->initRoad(roadName, xLocation, yLocation, length, heading);
	} while (symbol == ',');
	if (symbol != '}')
	{
		return;
	}
}

void JSONLoad::LoadStopSign(StopSign* roadItem, istream& stream)
{
	double mm;
	string temp;
	getline(stream, temp, ':');
	temp.pop_back();
	temp = temp.substr(1,temp.size()-1);
	cout << "Temp 1 in LSS: " << temp << endl;

	getline(stream, temp);
	cout << "Temp 2 in LSS: " << temp << endl;
	mm = stod(temp);
	roadItem->setMM(mm);
	//Sets StopSign MM
}

void JSONLoad::LoadSpeedLimit(SpeedLimit* roadItem, istream& stream)
{
	double mm, spd;
	string temp;

	getline(stream, temp, ':');
	temp.pop_back();
	temp = temp.substr(1,temp.size()-1);
	cout << "Temp 1 in LSL: " << temp << endl;
	getline(stream, temp);
	temp.pop_back();
	cout << "Temp 2 in LSL: " << temp << endl;
	mm = stod(temp);
	roadItem->setMM(mm);
	//Sets MileMarker and Val


	getline(stream, temp, ':');
	temp.pop_back();
	temp = temp.substr(1,temp.size()-1);
	cout << "Temp 3 in LSL: " << temp << endl;
	getline(stream, temp);
	//temp.pop_back();
	cout << "Temp 4 in LSL: " << temp << endl;
	spd = stod(temp);
	roadItem->setSpeedLimit(spd);
	//Sets SpeedLimit and Val
}

