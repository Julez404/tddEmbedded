#include "../unity.framework/src/unity.h"
#include "stdint.h"
#include "../src/LedDriver/LedDriver.h"

//TEST_GROUP(LedDriver);
static uint16_t testLeds;

void setUp()
{
    LedDriver_Init(&testLeds);
}

void test_LedsOffAfterCreate()
{
    uint16_t ledArray = 0xffff;
    LedDriver_Init(&ledArray);
    TEST_ASSERT_EQUAL_HEX16(0, ledArray);
}

void test_OneLedCanBeTurnedOn()
{
    LedDriver_TurnLedOn(5);
    TEST_ASSERT_BIT_HIGH(5, testLeds);
}

void test_TurnAllLedsOn()
{
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, testLeds);
}

void test_OneLedCanBeTurnedOff()
{
    LedDriver_TurnAllOn();
    LedDriver_TurnLedOff(5);
    TEST_ASSERT_BIT_LOW(5, testLeds);
    LedDriver_TurnLedOff(0);
    TEST_ASSERT_BIT_LOW(0, testLeds);
}