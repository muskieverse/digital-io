#ifndef __DIGITAL_IO_H
#define __DIGITAL_IO_H
#include "application.h"

class   DigitalInput
{
    public:
                DigitalInput();
                DigitalInput(int pin, PinMode mode, bool active_low=false);

        void    Scan();
        
        bool    RisingEdge();
        bool    FallingEdge();
        bool    State();
        
        // Properties        
        void    Pin(int pin);
        void    Mode(PinMode mode);
        void    ActiveLow(bool active_low);
        
    private:
    
        void    Initialize();
        
        int     pin_;
        PinMode mode_;
        bool    active_low_;
        
        bool    this_scan_;
        bool    last_scan_;
        bool    flag_active_;
        bool    rising_edge_;
        bool    falling_edge_;
};

class   DigitalOutput
{
    public:
    
                DigitalOutput();
                DigitalOutput(int pin, bool active_low=false);
                
        void    Off();
        void    On();
        void    State(bool state);
        void    Toggle();
        
        // Properties        
        void    Pin(int pin);
        void    ActiveLow(bool active_low);
        
    private:

        void    Initialize();

        int     pin_;
        bool    active_low_;
};

#endif  /* __DIGITAL_IO_H */
