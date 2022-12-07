#ifndef SUI_H_
#define SUI_H_

#include "Common.h"
#include "GUI.h"

class Road;

class Container
{
public:
	virtual ~Container() = default;

	char** map = new char*[CharMapSize];
};


class CharMatrix : public Container
{
public:
	CharMatrix();
};

class IPrintDriver
{
public:
    virtual void PrintRoad(Road* road, Container o) {};
    virtual void PrintCar(Car car, Container o) {};
};

class ConsolePrint : public IPrintDriver
{

public:
	void PrintRoad(Road* road, Container o);
    void PrintCar(Car car, Container o);
};


#endif /* SUI_H_ */
