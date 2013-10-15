#ifndef LOGIC_I_STEPPER_REGISTRAR_H
#define LOGIC_I_STEPPER_REGISTRAR_H

class IStepper;

class IStepperRegistrar
{
    public:
        IStepperRegistrar() {}
        ~IStepperRegistrar() {}

        virtual void suscribe(IStepper& stepper) = 0;
        virtual void unsuscribe(IStepper& stepper) = 0;
};

#endif

