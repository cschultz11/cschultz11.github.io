#ifndef DYNAMICITEMS_H
#define DYNAMICITEMS_H

#include <iostream>
#include <string>

namespace Constants
{
	//Begin Constants for Vehicles
	static const double CarAccRate = 3.5;
	static const double LightAccRate = 2.5;
	static const double HeavyAccRate = 1.0;

	static const double CarDecRate = 7.0;
	static const double LightDecRate = 5.0;
	static const double HeavyDecRate = 2.0;

	static const double MPStoMPH = 2.237;
	static const double MPStoKPH = 3.6;
	//End Constants for Vehicles

	//Start Constants for Map
	static const double MetersToMiles = 0.000621371;
	static const double MetersToKm = 0.001;
	static const int CharMapSize = 40;
	static const double WorldSize = 200.0;
	//End Constants for Map
}

using namespace Constants;

enum class Color
{
  green,
  yellow,
  red
};

class DynamicItems
{
	public:
		virtual void UpDate(int seconds)
		{

		}
};

class TrafficLight : public DynamicItems
{
private:
	int redTime, yellowTime, greenTime;
	int timeOn = 0;
	Color startColor;
	double milemarker;
public:
	TrafficLight(int rT, int yT, int gT, Color startC, double MM)
	{
		redTime = rT;
		yellowTime = yT;
		greenTime = gT;
		startColor = startC;
		milemarker = MM;
	}
	Color getSColor()
	{
		return startColor;
	}

	int getGT()
	{
		return greenTime;
	}

	int getYT()
	{
		return yellowTime;
	}

	int getRT()
	{
		return redTime;
	}

	void UpDate(int seconds)
	{
		int c = (int)getSColor();
		std::string temp;
		if(c == 0)
		{
			temp = "Green";
		}
		else if(c == 1)
		{
			temp = "Yellow";
		}
		else if(c == 2)
		{
			temp = "Red";
		}
		std::cout << "Starting Color: " << temp << std::endl;
		int counter = 0;
		if(getSColor() == Color::green)
		{
			do
			{
				timeOn = 0;
				do
				{
					std::cout << "Color: Green" << std::endl;
					timeOn++;
					counter++;
				} while (timeOn < greenTime);
				timeOn = 0;
				do
				{
					std::cout << "Color: Yellow" << std::endl;
					timeOn++;
					counter++;
				} while (timeOn < yellowTime);
				timeOn = 0;
				do
				{
					std::cout << "Color: Red" << std::endl;
					timeOn++;
					counter++;
				} while (timeOn < redTime);
			} while(counter < seconds);
			std::cout << std::endl;
		}
		else if(getSColor() == Color::red)
		{
			do
			{
			timeOn = 0;
				do
				{
					std::cout << "Color: Red" << std::endl;
					timeOn++;
					counter++;
				} while (timeOn < redTime);
				timeOn = 0;
				do
				{
					std::cout << "Color: Green" << std::endl;
					timeOn++;
					counter++;
				} while (timeOn < greenTime);
				timeOn = 0;
				do
				{
					std::cout << "Color: Yellow" << std::endl;
					timeOn++;
					counter++;
				} while (timeOn < yellowTime);
			} while(counter < seconds);
			std::cout << std::endl;
		}
		else if(getSColor() == Color::yellow)
		{
			do
			{
				timeOn = 0;
				do
				{
					std::cout << "Color: Yellow" << std::endl;
					timeOn++;
					counter++;
				} while (timeOn < yellowTime);
				timeOn = 0;
				do
				{
					std::cout << "Color: Red" << std::endl;
					timeOn++;
					counter++;
				} while (timeOn < redTime);
				timeOn = 0;
				do
				{
					std::cout << "Color: Green" << std::endl;
					timeOn++;
					counter++;
				} while (timeOn < greenTime);
			} while(counter < seconds);
		}
	}
};

#endif
