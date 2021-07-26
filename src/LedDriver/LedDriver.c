// Controls 16 LEDs
// Tun Off On individual LEDs
// Turn all off/on
// Query State
// PowerOn (Init) all On
// 0 = LED off
// LSB = LED1; MSB = LED16

// TESTS

// All LEDs are on till initialized  (/)
// Single one can be turned Off -> (/)
// Single One can be turned on -> (/)
// Multiple LEDs can be tunred off/on (all)
// Query LED state -> (/)
// Check boundry values -> (x)
// Check out of bounds values (x)

#include "stdint.h"
#include "LedDriver.h"
#include "stdbool.h"

static uint16_t *ledArrayAddress;

static void ChangeLedState(uint16_t ledNumber, bool turnLedOn);

void LedDriver_Init(uint16_t *_address)
{
    ledArrayAddress = _address;
    LedDriver_TurnAllOff();
}

void LedDriver_TurnAllOn()
{
    *ledArrayAddress = UINT16_MAX;
}

void LedDriver_TurnAllOff()
{
    *ledArrayAddress = 0;
}

void LedDriver_TurnLedOn(int ledNumber)
{
    ChangeLedState(ledNumber, true);
}

void LedDriver_TurnLedOff(int ledNumber)
{
    ChangeLedState(ledNumber, false);
}

bool LedDriver_GetLedState(int ledNumber)
{
    if (*ledArrayAddress & (1 << ledNumber))
        return true;
    else
        return false;
}

static void ChangeLedState(uint16_t ledNumber, bool turnLedOn)
{
    if (turnLedOn)
        *ledArrayAddress |= (1 << ledNumber);
    else
        *ledArrayAddress &= ~(1 << ledNumber);
}
