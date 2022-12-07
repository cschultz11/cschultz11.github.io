#ifndef JSON_H_
#define JSON_H_

#include <ostream>
#include <istream>

using namespace std;

class Map;
class Road;
class StopSign;
class SpeedLimit;

class JSONSave
{
public:
	void SaveMap(Map* map, ostream& str);
	void SaveRoad(Road* rd, ostream& str);
	void SaveStopSign(StopSign* roadItem, ostream& str);
	void SaveSpeedLimit(SpeedLimit* roadItem, ostream& str);
};

class JSONLoad
{
public:
	void LoadMap(Map* map, istream& str);
	void LoadRoad(Road* rd, istream& str);
	void LoadStopSign(StopSign* roadItem, istream& str);
	void LoadSpeedLimit(SpeedLimit* roadItem, istream& str);
};

#endif /* JSON_H_ */
