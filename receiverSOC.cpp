#include "receiverSOC.h"

std::vector<int> extractSOCData(std::string inputBuffer)
{
    std::string tempBuffer = inputBuffer;
    std::string extractedSOC;
    int found,value = 0;
    std::vector<int> SOCValues;
    std::string findSOC = "SOC";
    int sizeOfString = findSOC.size();

    found = tempBuffer.find(findSOC);
    extractedSOC = tempBuffer.substr(found+sizeOfString+1,2);
    std::istringstream(extractedSOC) >> value;
    SOCValues.push_back(value);

    for(int i=1; i<MAX_INPUTS; i++)
    {
        found = tempBuffer.find(findSOC, found+i);
        extractedSOC = tempBuffer.substr(found+sizeOfString+1,2);
        std::istringstream(extractedSOC) >> value;
        SOCValues.push_back(value);
    }
    return SOCValues;
}

int calculateMaxSOCValue(std::vector<int> socReadings)
{
    int maxSOC = *max_element(socReadings.begin(), socReadings.end());
    return maxSOC;
}

int calculateMinSOCValue(std::vector<int> socReadings)
{
    //int minSOC = *min_element(socReadings.begin(), socReadings.end());
    std::sort(socReadings.begin(), socReadings.end());
    int minSOC = socReadings[0];
    return minSOC;
}

void printSOCStatistics(int maxSOC, int minSOC, std::vector<float> simpleMovingAverageValueSOC)
{
   std::cout << "The Max SOC data recorded is " << maxSOC << "\n" << "The Minimum SOC data recorded is " << minSOC << "\n";
   std::cout << "The calculated simple moving averages of the last 5 entries is " << "\n";
   for(unsigned int i = 0; i<simpleMovingAverageValueSOC.size(); i++)
   {
       std::cout << simpleMovingAverageValueSOC[i] << "\n";
   }
}
