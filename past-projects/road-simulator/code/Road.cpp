#include "Road.h"
#include "SUI.h"
#include "roadItem.h"

#include <iostream>

Road::Road(std::string streetName, double locX, double locY, double len, Heading hdg)
{
            //head = new RoadItemsElement();

            name = streetName;
            length = len;
            heading = hdg;
            xlocation = locX;
            ylocation = locY;
            NumOfRoads++;

        	 head = NULL;
//             head->setPrev(NULL);
//             cout << "SET HEAD PREV TO NULL"<< endl;
//             head->setNext(NULL);
}

Road::Road()
{
            name = "";
            length = 0;
            heading = Heading::North;
            xlocation = 0;
            ylocation = 0;
            NumOfRoads = 0;

            head = NULL;
            //	 head->setRoadItem(NULL);
            //           head->setPrev(NULL);
            //           head->setNext(NULL);
}

void Road::initRoad(string streetName, double locX, double locY, double len, Heading hdg)
{
    head->setRoadItem(NULL);
    head->setPrev(NULL);
    head->setNext(NULL);

	name = streetName;
	length = len;
	heading = hdg;
	xlocation = locX;
	ylocation = locY;
	NumOfRoads++;
}

    double Road::GetLength() { return length; }
    double Road::GetXLocation() { return xlocation; }
    double Road::GetYLocation() { return ylocation; }
    Heading Road::GetHeading() { return heading; }
    std::string Road::GetRoadName() { return name; }
    RoadItemsElement* Road::getHead() {return head;}


    void Road::InsertNewItemBefore(RoadItem* current, RoadItem* newItem)
    {
    	RoadItemsElement* cur = new RoadItemsElement();
    	RoadItemsElement* newit = new RoadItemsElement();
    	head->setPrev(current);
    	newit->setNext(current);
    	cur->setPrev(newItem);
    	newit->getPrev()->setNext(newItem);

//    	head->setPrev(current);
//    	newItem->setNext(current);
//    	current->setPrev(newItem);
//    	newItem->getPrev().SetNext(newItem);
    }

    void Road::InsertNewItemAfter(RoadItem* current, RoadItem* newItem)
    {
    	RoadItemsElement* hd = new RoadItemsElement();
    	hd->setNext(newItem);
    	hd->setPrev(current);
//    	RoadItemsElement cur, newit;
//    	cur.setRoadItem(current);
//    	newit.setRoadItem(newItem);
//
//    	newit.setNext(cur.getNext()->getRoadItem());
//        cur.setNext(newItem);
//        newit.setPrev(current);
//        if (newit.getNext() != NULL)
//        {
//        	newit.getNext()->setPrev(newItem);
//        }
    }

    void Road::AddRoadItem(RoadItem* roadItem)
    {
    	Road* rd = roadItem->setCurrentRoad(this);
    	RoadItem* currentItem = new RoadItem();
        if(rd->getHead() == NULL)
        {
        	currentItem = NULL;
        }
        while (currentItem != NULL)
        {
        	currentItem = rd->getHead()->getNext()->getRoadItem();
            if (currentItem->getMM() > roadItem->getMM())
            {
            	rd->InsertNewItemBefore(currentItem, roadItem);
            	return;
            }
         }
         rd->InsertNewItemAfter(currentItem, roadItem);
    }



    void Road::Print(IPrintDriver* print, Container* o)
    {
        print->PrintRoad(this, *o);
    }

    void Road::Save(JSONSave* sv, ostream& str)
    {
    	sv->SaveRoad(this, str);
    }
    void Road::Load(JSONLoad* ld, istream& str)
    {
    	ld->LoadRoad(this, str);
    }

