#ifndef COMMON_H_
#define COMMON_H_

#include "DynamicItems.h"

class Conversions
{
public:
	static int WCpointToCCpoint(double val)
    {
        return (int)(val * (CharMapSize / WorldSize) + (CharMapSize / 2));
    }

    static int WClengthToCClength(double val)
    {
        return (int)(val * (CharMapSize / WorldSize));
    }
};


#endif /* COMMON_H_ */
