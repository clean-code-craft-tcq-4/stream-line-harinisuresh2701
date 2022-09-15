#ifndef RECEIVERSOC_H
#define RECEIVERSOC_H

#include "common.h"

std::vector<int> extractSOCData(std::string inputBuffer);
int calculateMaxSOCValue(std::vector<int> buffer);
int calculateMinSOCValue(std::vector<int> buffer);
void printSOCStatistics(int maxSOC, int minSOC, std::vector<float> simpleMovingAverageValueSOC);


#endif
