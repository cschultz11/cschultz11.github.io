using namespace std;

#include <iostream>
#include <string>
#include <list>
#include <typeinfo>
#include <fstream>

#include "SUI.h"
#include "GUI.h"
#include "Map.h"
#include "Road.h"
#include "roadItem.h"
#include "Simulation.h"


int main()
{
			Simulation* sim = new Simulation();
			GUI* simInput = new MetricGUI();
			Map* map = new Map();
			IPrintDriver *cp = new ConsolePrint();
			JSONSave *sd = new JSONSave();
			JSONLoad *ld = new JSONLoad();

			// Load in map
//			ifstream loadfile;
//			loadfile.open("JSON Files/ProjectInput.json");
//			cout << "Opened file." << endl;
//			//Use JSON Files/CrosstownInput.json for Week 8 example
//			cout << "Loading file..." << endl;
//			map.Load(ld, loadfile);
//			cout << "Loaded file!" << endl;

//			cout << "Creating New Roads..." << endl;
			Road Uptown = simInput->CreateRoad("Uptown", 0.0, -0.09, .180, Heading::North);
			map->AddRoad(&Uptown);
			TrafficLight TL1 = simInput->CreateTrafficLight(7, 2, 5, Color::green, 0.0);
			sim->AddDynamicItem(&TL1);
			//TrafficLight* TL1 = new TrafficLight(7, 2, 5, Color::green, 0.0);
//			cout << "Added Uptown" << endl;
			Road Crosstown = simInput->CreateRoad("Crosstown", -0.09, 0.0, .180, Heading::East);
			map->AddRoad(&Crosstown);
			TrafficLight TL2 = simInput->CreateTrafficLight(7, 2, 5, Color::red, 0.0);
			sim->AddDynamicItem(&TL2);
			//TrafficLight* TL2 = new TrafficLight(7, 2, 5, Color::red, 0.0);
//			cout << "Added Crosstown" << endl;
			StopSign sign = simInput->CreateStopSign(.01);
			Crosstown.AddRoadItem(&sign);
//			cout << "Added StopSign .01" << endl;
			StopSign sign2 = simInput->CreateStopSign(.23);
			Uptown.AddRoadItem(&sign2);
//			cout << "Added StopSign .23" << endl;
			StopSign sign3 = simInput->CreateStopSign(.32);
			Uptown.AddRoadItem(&sign3);
//			cout << "Added StopSign .32" << endl;
			StopSign sign4 = simInput->CreateStopSign(.302);
			Uptown.AddRoadItem(&sign4);
//			cout << "Added StopSign .302" << endl;
			SpeedLimit limit = simInput->CreateSpeedLimit(80.0, .02);
			Crosstown.AddRoadItem(&limit);
//			cout << "Added SpeedLimit 80, .02" << endl;
			SpeedLimit limit2 = simInput->CreateSpeedLimit(50.0, .123);
			Uptown.AddRoadItem(&limit2);
//			cout << "Added SpeedLimit 50, .123" << endl;
//			cout << "Ended Creating New Roads" << endl;



			// Display map
			//cout << "Displaying map..." << endl;
			CharMatrix *cm = new CharMatrix();
			map->Print(cp, cm);
			for (int i = 0; i < CharMapSize; i++) {
				string s = "";
				for (int j = 0; j < CharMapSize; j++) {
					s = s + cm->map[i][j];
				}
				cout << s << endl;
			}
			//cout << "Displayed map!" << endl;



			// Save map
			ofstream savefile;
			savefile.open("JSON Files/ProjectOutput.json"); //Saves file
			//cout << "Opened file." << endl;
			//Use JSON Files/CrosstownInput.json for example
			//cout << "Saving file..." << endl;
			map->Save(sd, savefile);
			//cout << "Saved file!" << endl;

			sim->UpDate(20);

			//Traffic Lights only
			//TrafficLight* TL1 = new TrafficLight(7, 2, 5, Color::green, 0.0);
			//TrafficLight* TL2 = new TrafficLight(7, 2, 5, Color::red, 0.0);

		return 0;
}
