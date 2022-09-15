#ifndef BMSRECEIVER_H
#define BMSRECEIVER_H

#include "common.h"
#include "receiverTemperature.h"
#include "receiverSOC.h"

std::string readFromConsole();
std::vector<float> calculateSimpleMovingAverageValue(std::vector<int> buffer,int sampleSize);
void receiverCentralControl();

#endif
