#include "SUI.h"
#include "Road.h"
#include "Map.h"
#include "Common.h"

//    virtual void IPrintDriver::PrintRoad(Road road, Container o);
//    virtual void IPrintDriver::PrintCar(Car car, Container o);


	void ConsolePrint::PrintRoad(Road* road, Container o)
    {
        CharMatrix cm = static_cast<CharMatrix&>(o);
		//CharMatrix* cm = o;
        int x, y;
        int CCx;
        Conversions roadX;
        CCx = roadX.WCpointToCCpoint(road->GetXLocation());
        int CCy;
        Conversions roadY;
        CCy = roadY.WCpointToCCpoint(-road->GetYLocation());
        int distance = 0;
        int CCRoadLength;
        Conversions roadLen;
        CCRoadLength = roadLen.WClengthToCClength(road->GetLength());
        switch (road->GetHeading())
        {
            case Heading::North:
                x = (int)CCx;
                if (x >= 0 && x < CharMapSize)
                {
                    while (distance < CCRoadLength)
                    {
                        y = (int)(CCy - distance);
                        if (y >= 0 && y < CharMapSize)
                        {
                            cm.map[y][x] = '|';
                            cm.map[y][x + 2] = '|';
                            cm.map[y][x + 4] = '|';
                        }
                        distance += 1;
                    }

                }
                break;
            case Heading::South:
                break;
            case Heading::East:
                y = (int)CCy;
                if (y >= 0 && y < CharMapSize)
                {
                    while (distance < CCRoadLength)
                    {
                        x = (int)(CCx + distance);
                        if (x >= 0 && x < CharMapSize)
                        {
                            cm.map[y][x] = '-';
                            cm.map[y + 2][x] = '-';
                            cm.map[y + 4][x] = '-';
                        }
                        distance += 1;
                    }

                }
                break;
            case Heading::West:
            break;
            default:
                break;
        }
    }

    void ConsolePrint::PrintCar(Car car, Container o)
    {

    }
