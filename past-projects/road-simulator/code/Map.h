#ifndef MAP_H_
#define MAP_H_

#include <vector>

#include "SUI.h"
#include "Road.h"
#include "JSON.h"

class Map
{
private:
	std::vector<Road*> roads;

public:
	Map();
	vector<Road*> GetRoad();
    void AddRoad(Road* road);
    void Print(IPrintDriver* pd, Container* o);

    void Save(JSONSave* sv, ostream& str);
    void Load(JSONLoad* ld, istream& str);
};

#endif /* MAP_H_ */
