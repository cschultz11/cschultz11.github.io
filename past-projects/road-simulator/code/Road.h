#ifndef ROAD_H_
#define ROAD_H_

//#include "SUI.h"
#include "JSON.h"

class IPrintDriver;
class Container;
class RoadItemsElement;
class RoadItem;

enum class Heading
{
  North,
  South,
  East,
  West
};

class Road
    {

private:
	std::string name;
    double length;
    double xlocation;
    double ylocation;
    Heading heading;
    RoadItemsElement* head;

public:
    int NumOfRoads = 0;

    void initRoad(string streetName, double locX, double locY, double len, Heading hdg);

    Road();
    Road(std::string streetName, double locX, double locY, double len, Heading hdg);

    double GetLength();
    double GetXLocation();
    double GetYLocation();
    Heading GetHeading();
    std::string GetRoadName();
    RoadItemsElement* getHead();

    void AddRoadItem(RoadItem* roadItem);

    void InsertNewItemBefore(RoadItem* current, RoadItem* newItem);

    void InsertNewItemAfter(RoadItem* current, RoadItem* newItem);

    void Print(IPrintDriver* print, Container *o);



    void Save(JSONSave* sv, ostream& str);
    void Load(JSONLoad* ld, istream& str);
};



#endif /* ROAD_H_ */
