#ifndef LOGIC_CHRONOMETER_H
#define LOGIC_CHRONOMETER_H

class IChronometer
{
    public:
        IChronometer() {}
        virtual ~IChronometer() {}
        virtual void restart() = 0;
        virtual long count() const = 0;
};

#endif

