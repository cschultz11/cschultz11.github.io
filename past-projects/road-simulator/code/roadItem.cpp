#include "roadItem.h"
#include "Road.h"

#include <iostream>
#include <vector>

using namespace std;

double RoadItem::getMM()
{
	double MM = mm;
	return MM;
}

void RoadItem::setMM(double dist)
{
	mm = dist;
}

Road* RoadItem::setCurrentRoad(Road* rd)
{
	return rd;
}

//virtual void RoadItem::Save(JSONSave* sv, ostream& str)
//{
//};

StopSign::StopSign(double dist)
{
	setMM(dist);
}

StopSign::StopSign()
{
	//setMM(0);
}

void StopSign::Save(JSONSave* sv, ostream& str)
{
	sv->SaveStopSign(this, str);
}

//void StopSign::Load(JSONLoad* ld, ostream& str)
//{
//	ld->LoadStopSign(this, str);
//}

SpeedLimit::SpeedLimit(double postedSpeed, double dist)
{
	speedLimit = postedSpeed;
	setMM(dist);
}

SpeedLimit::SpeedLimit()
{

}

double SpeedLimit::setSpeedLimit(double spd)
{
	speedLimit = spd;
}

double SpeedLimit::getSpeedLimit()
{
	double lim = speedLimit;
	return lim;
}

void SpeedLimit::Save(JSONSave* sv, ostream& str)
{
	sv->SaveSpeedLimit(this, str);
}

//void SpeedLimit::Load(JSONLoad* ld, ostream& str)
//{
//	ld->LoadSpeedLimit(this, str);
//}

RoadItemsElement::RoadItemsElement()
{
//	roadItem = hd->getRoadItem();
//	nextRoadItem = hd->getNext();
//	prevRoadItem = hd->getPrev();

//	roadItem = NULL;
//	nextRoadItem = NULL;
//	prevRoadItem = NULL;
}

RoadItem* RoadItemsElement::getRoadItem()
{
	RoadItem* rd = roadItem;
	return rd;
}

void RoadItemsElement::setRoadItem(RoadItem* rd)
{
	RoadItem* roaditem = getRoadItem();
	roaditem = rd;
}

void RoadItemsElement::setNext(RoadItem* ri)
{
	RoadItemsElement* n = getNext();
	n->setRoadItem(ri);
}

void RoadItemsElement::setPrev(RoadItem* ri)
{
	RoadItemsElement* p = getPrev();
	p->setRoadItem(ri);
}

RoadItemsElement* RoadItemsElement::getNext()
{
	RoadItemsElement* nxt = nextRoadItem;
	return nxt;
}

RoadItemsElement* RoadItemsElement::getPrev()
{
	RoadItemsElement* prv = prevRoadItem;
	return prv;
}

void RoadItemsElement::addNew(RoadItem* rItem)
{
	nextRoadItem->setNext(rItem);
}
