#ifndef ROADITEM_H_
#define ROADITEM_H_

#include <ostream>
#include <vector>

#include "JSON.h"

class RoadItem
{
private:
	double mm = 0.0;

public:
	double getMM();
	void setMM(double dist);
	Road* setCurrentRoad(Road* rd);
	virtual void Save(JSONSave* sv, ostream& str) {};
};

class StaticRoadItem : public RoadItem
{

};

class StopSign : public StaticRoadItem
{
public:
	StopSign(double dist);
	StopSign();
	void Save(JSONSave* sv, ostream& str) override;
	//void Load(JSONLoad* ld, ostream& str);
};

class SpeedLimit : public StaticRoadItem
{
private:
	double speedLimit;

public:
	SpeedLimit(double postedSpeed, double dist);
	SpeedLimit();
	double setSpeedLimit(double spd);
	double getSpeedLimit();
	void Save(JSONSave* sv, ostream& str) override;
	//void Load(JSONLoad* ld, ostream& str);
};

class RoadItemsElement
{
private:
	RoadItem* roadItem;
	RoadItemsElement* nextRoadItem;
	RoadItemsElement* prevRoadItem;
	void addNext(RoadItem* roadItem);
	void addPrev(RoadItem* roadItem);

public:
	RoadItemsElement();
	RoadItem* getRoadItem();
	void setRoadItem(RoadItem* rd);
	void setNext(RoadItem* ri);
	void setPrev(RoadItem* ri);
	RoadItemsElement* getNext();
	RoadItemsElement* getPrev();
	void addNew(RoadItem* rItem);
};


#endif /* ROADITEM_H_ */
