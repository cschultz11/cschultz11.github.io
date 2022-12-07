#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <vector>

class DynamicItems;

class Simulation
{
private:
	std::vector<DynamicItems*> dList;

public:
	std::vector<DynamicItems*> getSim();
	void AddDynamicItem(DynamicItems* d);
	void UpDate(int seconds);
};


#endif /* SIMULATION_H_ */
