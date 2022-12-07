#ifndef GUI_H_
#define GUI_H_

#include <string>
#include <iostream>

#include "Interface.h"
#include "Road.h"
#include "roadItem.h"
#include "DynamicItems.h"

class GUI : public ISimInput, ISimOutput
{
public:
	virtual Road CreateRoad(std::string name, double locx, double locy, double len, Heading hdg) = 0; // @suppress("No return")

	virtual double GetSpeed(Vehicle* v) = 0;

	virtual SpeedLimit CreateSpeedLimit(double speed, double location) = 0;

	virtual StopSign CreateStopSign(double location) = 0;

	virtual TrafficLight CreateTrafficLight(int rT, int yT, int gT, Color startC, double MM) = 0;

	//virtual void SetSpeedLimit(Vehicle* v, double speed) {}
};

class MetricGUI : public GUI {
public:
	Road CreateRoad(std::string name, double locx, double locy, double len, Heading hdg) override
	{
		return  *(new Road(name, locx / MetersToKm, locy / MetersToKm, len / MetersToKm, hdg));
	}

	double GetSpeed(Vehicle* v)
	{
		return v->GetCurrentSpeed() * MPStoKPH;
	}

	SpeedLimit CreateSpeedLimit(double speed, double location) override
	{
		return *(new SpeedLimit(speed, location));
	}

	StopSign CreateStopSign(double location) override
	{
		return *(new StopSign(location));
	}
	TrafficLight CreateTrafficLight(int rT, int yT, int gT, Color startC, double MM) override
	{
		return *(new TrafficLight(rT, yT, gT, startC, MM));
	}
	/*
	void SetSpeedLimit(Vehicle* v, double speed)
	{
		v->SetDesiredSpeed(speed/MPStoKPH);
	}
	*/
};

class ImperialGUI : public GUI {
public:
	Road CreateRoad(std::string name, double locx, double locy, double len, Heading hdg)
	{
	    return *(new Road(name, locx / MetersToMiles, locy / MetersToMiles, len / MetersToMiles, hdg));
	}

	double GetSpeed(Vehicle* v)
	{
		return v->GetCurrentSpeed() * MPStoMPH;
	}

	SpeedLimit CreateSpeedLimit(double speed, double location) override
	{
		return *(new SpeedLimit(speed, location));
	}

	StopSign CreateStopSign(double location) override
	{
		return *(new StopSign(location));
	}
	TrafficLight CreateTrafficLight(int rT, int yT, int gT, Color startC, double MM) override
	{
		return *(new TrafficLight(rT, yT, gT, startC, MM));
	}
	/*
	void SetSpeedLimit(Vehicle* v, double speed)
	{
		v->SetDesiredSpeed(speed/MPStoMPH);
	}
	*/
};

#endif
