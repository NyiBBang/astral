#ifndef LOGIC_CHRONOMETER_H
#define LOGIC_CHRONOMETER_H

#include "Units.h"

class IChronometer
{
    public:
        IChronometer() {}
        virtual ~IChronometer() {}
        virtual void restart() = 0;
        virtual quantity<si::time, double> count() const = 0;
};

#endif

