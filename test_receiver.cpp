#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"
#include "common.h"
#include "receiverTemperature.h"
#include "receiverSOC.h"
#include "bmsReceiver.h"

#define TEST_INPUTS 5

using namespace std;

TEST_CASE("To check if extractTemperatureData() extracts precisely the number of values set by macro MAX_INPUTS. In this case, 5 values") 
{
    std::string testString = "Sample_no:1, Temperature:45, SOC:80\nSample_no:2, Temperature:55, SOC:50\nSample_no:3, Temperature:50, SOC:40\nSample_no:4, Temperature:40, SOC:80\nSample_no:5, Temperature:65, SOC:70\nSample_no:6, Temperature:70, SOC:80";

    vector<int> temperatureData = extractTemperatureData(testString);
    int temperatureDataSize = temperatureData.size();
    REQUIRE(temperatureDataSize == TEST_INPUTS);
}

TEST_CASE("To check if createChargeValues() generates precisely the number of values set by macro MAX_INPUTS. In this case, 5 values") 
{
    std::string testString = "Sample_no:1, Temperature:45, SOC:80\nSample_no:2, Temperature:55, SOC:50\nSample_no:3, Temperature:50, SOC:40\nSample_no:4, Temperature:40, SOC:80\nSample_no:5, Temperature:65, SOC:70\nSample_no:6, Temperature:70, SOC:80";
    vector<int> chargeData = extractSOCData(testString);
    int chargeDataSize = chargeData.size();
    REQUIRE(chargeDataSize == TEST_INPUTS);
}

TEST_CASE("To verify functionality of calculateMaxTemperatureValue()" )
{
    std::vector<int> testTempVector = {10,20,40,60,100};
    int maxTemp = calculateMaxTemperatureValue(testTempVector);
    REQUIRE(maxTemp == 100);
}

TEST_CASE("To verify functionality of calculateMaxSOCValue()" )
{
    std::vector<int> testTempVector = {10,20,40,60,100};
    int maxTemp = calculateMaxSOCValue(testTempVector);
    REQUIRE(maxTemp == 100);
}

TEST_CASE("To verify functionality of calculateMinTemperature()" )
{
    std::vector<int> testTempVector = {10,20,40,60,100};
    int maxTemp = calculateMinTemperature(testTempVector);
    REQUIRE(maxTemp == 10);
}

TEST_CASE("To verify functionality of calculateMinSOCValue()" )
{
    std::vector<int> testTempVector = {10,20,40,60,100};
    int maxTemp = calculateMinSOCValue(testTempVector);
    REQUIRE(maxTemp == 10);
}
