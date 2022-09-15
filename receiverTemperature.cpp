#include "receiverTemperature.h"

std::vector<int> extractTemperatureData(std::string inputBuffer)
{
    std::string tempBuffer = inputBuffer;
    std::string extractedTemperature;
    int found,value = 0;
    std::vector<int> temperatureValues;
    std::string findTemperature = "Temperature";
    int sizeOfString = findTemperature.size();

    found = tempBuffer.find(findTemperature);
    extractedTemperature = tempBuffer.substr(found+sizeOfString+1,2);
    std::istringstream(extractedTemperature) >> value;
    temperatureValues.push_back(value);

    for(int i=1; i<MAX_INPUTS; i++)
    {
        found = tempBuffer.find(findTemperature, found+i);
        extractedTemperature = tempBuffer.substr(found+sizeOfString+1,2);
        std::istringstream(extractedTemperature) >> value;
        temperatureValues.push_back(value);
    }
    return temperatureValues;
}

int calculateMaxTemperatureValue(std::vector<int> temperatureReadings)
{
    int maxTemperature = *max_element(temperatureReadings.begin(), temperatureReadings.end());
    return maxTemperature;
}

int calculateMinTemperature(std::vector<int> temperatureReadings)
{
    //int minTemperature = *min_element(temperatureReadings.begin(), temperatureReadings.end());
    std::sort(temperatureReadings.begin(),temperatureReadings.end());
    int minTemperature = temperatureReadings[0];
    return minTemperature;
}

void printTemperatureStatistics(int maxTemperature, int minTemperature, std::vector<float> simpleMovingAverageValueTemperature)
{
   std::cout << "The Max Temperature data recorded is " << maxTemperature << "\n" << "The Minimum temperature data recorded is " << minTemperature << "\n";
   std::cout << "The calculated simple moving averages of the last 5 entries is " << "\n";
   for(unsigned int i = 0; i<simpleMovingAverageValueTemperature.size(); i++)
   {
       std::cout << simpleMovingAverageValueTemperature[i] << "\n";
   }
}
