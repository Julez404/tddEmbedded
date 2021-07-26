#include "unity_fixture.h"
#include "stdint.h"
#include "../src/LedDriver/LedDriver.h"

TEST_GROUP(LedDriver);
static uint16_t testLeds;

TEST_SETUP(LedDriver)
{
    LedDriver_Init(&testLeds);
}

TEST_TEAR_DOWN(LedDriver)
{
}

TEST(LedDriver, LedsOffAfterCreate)
{
    uint16_t ledArray = 0xffff;
    LedDriver_Init(&ledArray);
    TEST_ASSERT_EQUAL_HEX16(0, ledArray);
}

TEST(LedDriver, OneLedCanBeTurnedOn)
{
    LedDriver_TurnLedOn(5);
    TEST_ASSERT_BIT_HIGH(5, testLeds);
}

TEST(LedDriver, TurnAllLedsOn)
{
    LedDriver_TurnAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, testLeds);
}

TEST(LedDriver, OneLedCanBeTurnedOff)
{
    LedDriver_TurnAllOn();
    LedDriver_TurnLedOff(5);
    TEST_ASSERT_BIT_LOW(5, testLeds);
    LedDriver_TurnLedOff(0);
    TEST_ASSERT_BIT_LOW(0, testLeds);
}

TEST(LedDriver, QueryLedStates)
{
    LedDriver_TurnLedOn(10);
    TEST_ASSERT_TRUE(LedDriver_GetLedState(10));
    LedDriver_TurnLedOn(0);
    TEST_ASSERT_TRUE(LedDriver_GetLedState(0));
    LedDriver_TurnLedOn(15);
    TEST_ASSERT_TRUE(LedDriver_GetLedState(15));
}