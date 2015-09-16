#include "application.h"
#include "digital_io.h"

DigitalInput::DigitalInput()
    : pin_(0)
    , mode_(INPUT)
    , active_low_(false)
    , this_scan_(false)
    , last_scan_(false)
    , flag_active_(false)
    , rising_edge_(false)
    , falling_edge_(false)
{
}

DigitalInput::DigitalInput(int pin, PinMode mode, bool active_low)
    : pin_(pin)
    , mode_(mode)
    , active_low_(active_low)
    , this_scan_(false)
    , last_scan_(false)
    , flag_active_(false)
    , rising_edge_(false)
    , falling_edge_(false)
{
    Initialize();
}

void    DigitalInput::Initialize()
{
    pinMode(pin_, mode_);
    
    this_scan_      = State();
    last_scan_      = this_scan_;
    flag_active_    = false;
    rising_edge_    = false;
    falling_edge_   = false;
}

void    DigitalInput::ActiveLow(bool active_low)
{
    active_low_ = active_low;
    Initialize();
}

void    DigitalInput::Pin(int pin)
{
    pin_    = pin;
    Initialize();
}

void    DigitalInput::Mode(PinMode mode)
{
    mode_   = mode;
    Initialize();
}

bool    DigitalInput::State()
{
    if (active_low_ == true)
    {
        return (digitalRead(pin_) == LOW);
    }
    else
    {
        return (digitalRead(pin_) == HIGH);
    }
}

void    DigitalInput::Scan()
{
    this_scan_    = State();
    rising_edge_  = this_scan_ && last_scan_ && flag_active_;
    falling_edge_ = !this_scan_ && !last_scan_ && flag_active_;
    flag_active_  = ((this_scan_ && !last_scan_) || (last_scan_ && !this_scan_)) && !flag_active_;
    last_scan_    = this_scan_;
}

bool    DigitalInput::RisingEdge()
{
    return (rising_edge_);
}

bool    DigitalInput::FallingEdge()
{
    return (falling_edge_);
}

//
//  Digital Output
//

DigitalOutput::DigitalOutput()
    : pin_(0)
    , active_low_(false)
{
}

DigitalOutput::DigitalOutput(int pin, bool active_low)
    : pin_(pin)
    , active_low_(active_low)
{
    Initialize();
}

void    DigitalOutput::Initialize()
{
    pinMode(pin_, OUTPUT);
    Off();
}

void    DigitalOutput::ActiveLow(bool active_low)
{
    active_low_ = active_low;
    Initialize();
}

void    DigitalOutput::Pin(int pin)
{
    pin_    = pin;
    Initialize();
}

void    DigitalOutput::Off()
{
    if (active_low_ == true)
    {
        digitalWrite(pin_, HIGH);
    }
    else
    {
        digitalWrite(pin_, LOW);
    }
}

void    DigitalOutput::On()
{
    if (active_low_ == true)
    {
        digitalWrite(pin_, LOW);
    }
    else
    {
        digitalWrite(pin_, HIGH);
    }
}

void    DigitalOutput::State(bool state)
{
    if (state == true)
    {
        On();
    }
    else
    {
        Off();
    }
}


