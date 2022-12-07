#include "Simulation.h"
#include "DynamicItems.h"

#include <iostream>

using namespace std;


std::vector<DynamicItems*> Simulation::getSim()
{
	return dList;
}

void Simulation::AddDynamicItem(DynamicItems* d)
{
	dList.push_back(d);
}

void Simulation::UpDate(int seconds)
{
	int count = 1;
//	cout << "BEGIN" << endl;
	for(DynamicItems* d : dList)
	{
		cout << "Traffic Light #" << count << endl;
		d->UpDate(20);
		count++;
	}
}
