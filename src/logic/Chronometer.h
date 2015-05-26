#ifndef LOGIC_CHRONOMETER_H
#define LOGIC_CHRONOMETER_H

#include "IChronometer.h"
#include <chrono>

class Chronometer final : public IChronometer
{
    public:
        Chronometer();
        void restart() override;
        TimeQuantity count() const override;

    private:
        std::chrono::system_clock::time_point last_;
};

#endif

