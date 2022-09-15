#ifndef RECEIVERTEMPERATURE_H
#define RECEIVERTEMPERATURE_H

#include "common.h"

std::vector<int> extractTemperatureData(std::string inputBuffer);
int calculateMaxTemperatureValue(std::vector<int> buffer);
int calculateMinTemperature(std::vector<int> buffer);
void printTemperatureStatistics(int maxTemperature, int minTemperature, std::vector<float> simpleMovingAverageValueTemperature);

#endif
