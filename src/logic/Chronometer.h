#ifndef LOGIC_CHRONOMETER_H
#define LOGIC_CHRONOMETER_H

#include "IChronometer.h"
#include <chrono>

class Chronometer final : public IChronometer
{
    public:
        Chronometer();
        virtual void restart();
        virtual quantity<si::time, double> count() const;

    private:
        std::chrono::system_clock::time_point last_;
};

#endif

