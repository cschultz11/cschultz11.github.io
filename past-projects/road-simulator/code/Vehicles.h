#ifndef VEHICLES_H
#define VEHICLES_H

#include "DynamicItems.h"

//Begin Vehicle
class Vehicle : public DynamicItems {
private:
	double currentSpeed = 0.0;
	double desiredSpeed;

protected:
	virtual void Accelerate(int seconds)
	{
	}

	virtual void Decelerate(int seconds)
  	{
   	}


	void SetCurrentSpeed(double speed)
	{
		if(currentSpeed <= speed) //When the vehicle accelerates
		{
			if(speed > desiredSpeed)
			{
				currentSpeed = desiredSpeed;
			}
			else
			{
				currentSpeed = speed;
			}
		}
		else //When the vehicle decelerates
		{
			if(speed < desiredSpeed)
			{
				currentSpeed = desiredSpeed;
			}
			else
			{
				currentSpeed = speed;
			}
		}
	}
public:
 	double GetCurrentSpeed()
   	{
 		return currentSpeed;
    }

 	void SetDesiredSpeed(double speed)
	{
		desiredSpeed = speed;
	}

	void UpdateSpeed(int seconds)
	{
		if(currentSpeed > desiredSpeed)
		{
			Decelerate(seconds);
		}
		else if(currentSpeed < desiredSpeed)
		{
			Accelerate(seconds);
		}
	}
};
//End Vehicle

//Begin Car
class Car: public Vehicle {
protected:
	void Accelerate(int seconds) override
	{
		SetCurrentSpeed(GetCurrentSpeed() + CarAccRate * seconds);
	}

	void Decelerate(int seconds) override
	{
		SetCurrentSpeed(GetCurrentSpeed() - CarDecRate * seconds);
	}
};
//End Car

//Begin Truck
class Truck: public Vehicle {
private:
	int loadWeight; //Measured in tons

public:
	Truck(int weight)
	{
		loadWeight = weight;
	}

protected:
	void Accelerate(int seconds) override
	{
		if(loadWeight <= 5)
		{
		SetCurrentSpeed(GetCurrentSpeed() + LightAccRate * seconds);
		}
		else
		{
			SetCurrentSpeed(GetCurrentSpeed() + HeavyAccRate * seconds);
		}
	}

	void Decelerate(int seconds) override
	{
		if(loadWeight <= 5)
		{
			SetCurrentSpeed(GetCurrentSpeed() - LightDecRate * seconds);
		}
		else
		{
			SetCurrentSpeed(GetCurrentSpeed() - HeavyDecRate * seconds);
		}
	}
};
//End Truck

#endif
