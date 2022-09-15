#include "bmsReceiver.h"

std::string readFromConsole()
{
    std::string tempbuffer,inputBuffer;
    for(int i = 0; i< MAX_INPUTS; i++)
    {
        getline(std::cin,tempbuffer);
        inputBuffer = inputBuffer + "\n" + tempbuffer;
    }
    return inputBuffer;
}

std::vector<float> calculateSimpleMovingAverageValue(std::vector<int> inputBuffer,int sampleSize)
{
    std::vector<float> SimpleMovingAverages;
    int inputBufferSize = inputBuffer.size();
    for(int cursor = inputBufferSize-1; cursor >= inputBufferSize - sampleSize ; cursor--)
    {
        float tempAverage = 0;
        float sum = 0;
        for(int i = 0; i< sampleSize; i++)
        {
            sum = sum + inputBuffer[cursor-1-i]; 
        }
        tempAverage = sum/sampleSize;
        SimpleMovingAverages.push_back(tempAverage);
    }
        return SimpleMovingAverages;
}

void receiverCentralControl()
{
    std::vector<float> SMA_Temperature,SMA_SOC;

    std::string buffer = readFromConsole();
    std::vector<int> temperatureReadings = extractTemperatureData(buffer);
    std::vector<int> socReadings = extractSOCData(buffer);
    int maxTemperature = calculateMaxTemperatureValue(temperatureReadings);
    int minTemperature = calculateMinTemperature(temperatureReadings);
    int minSOC = calculateMinSOCValue(socReadings);
    int maxSOC = calculateMaxSOCValue(socReadings);
    SMA_Temperature = calculateSimpleMovingAverageValue(temperatureReadings, SAMPLES);
    SMA_SOC = calculateSimpleMovingAverageValue(socReadings, SAMPLES);
    printTemperatureStatistics(maxTemperature, minTemperature, SMA_Temperature);
    printSOCStatistics(maxSOC, minSOC, SMA_SOC);
}
