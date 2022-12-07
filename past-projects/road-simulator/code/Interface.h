#ifndef INTERFACE_H
#define INTERFACE_H

#include "Vehicles.h"

class ISimOutput
{
public:
	virtual double GetSpeed(Vehicle* v) = 0;
};

class ISimInput
{
public:
	virtual void SetSpeedLimit(Vehicle* v, double speed)
	{
	}
};

#endif
