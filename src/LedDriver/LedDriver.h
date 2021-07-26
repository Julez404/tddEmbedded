#ifndef LED_DRV_H
#define LED_DRV_H

#include "stdio.h"
#include "stdbool.h"

void LedDriver_Init(uint16_t *_address);
void LedDriver_TurnAllOff(void);
void LedDriver_TurnAllOn(void);
void LedDriver_TurnLedOn(int ledNumber);
void LedDriver_TurnLedOff(int ledNumber);
bool LedDriver_GetLedState(int ledNumber);

#endif