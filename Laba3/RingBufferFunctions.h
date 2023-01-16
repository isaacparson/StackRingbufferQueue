#pragma once
#include <cstdint>
#include "RingBuffer.h"

void RingMenu();
void RingInit(int length);
void RingAdd();
void RingShow();
int FreeSpace();
int OccupiedSpace();
void RingAdd();
void RingPop();