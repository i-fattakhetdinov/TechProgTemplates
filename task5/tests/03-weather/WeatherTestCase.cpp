//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST_F(WeatherTestCase, GetResponseForCityInvalidArgument) {
    ASSERT_THROW(weather->GetResponseForCity("nonExistingCity"), std::invalid_argument);
}

TEST_F(WeatherTestCase, GetResponseForCity) {
    auto cityInfo = weather->GetResponseForCity("Moscow");
    auto answer = json::parse("{\"list\" : [{\"main\": {\"temp\": 8}}]}");
    ASSERT_EQ(cityInfo, answer);
}

TEST_F(WeatherTestCase, GetTemperature) {
    ASSERT_EQ(weather->GetTemperature("Madrid"), 29);
}

TEST_F(WeatherTestCase, GetDifferenceStringPlus) {
    std::string answer = "Weather in Madrid is warmer than in Moscow by 21 degrees";
    ASSERT_EQ(weather->GetDifferenceString("Madrid", "Moscow"), answer);
}

TEST_F(WeatherTestCase, GetDifferenceStringMinus) {
    std::string answer = "Weather in Moscow is colder than in Madrid by 21 degrees";
    ASSERT_EQ(weather->GetDifferenceString("Moscow", "Madrid"), answer);
}

TEST_F(WeatherTestCase, FindDiffBetweenTwoCities) {
    ASSERT_EQ(weather->FindDiffBetweenTwoCities("Madrid", "Moscow"), 21);
    ASSERT_EQ(weather->FindDiffBetweenTwoCities("Moscow", "Madrid"), -21);
}

TEST_F(WeatherTestCase, SetApiKey) {
    ASSERT_NO_THROW(weather->SetApiKey("myApiKey"));
}
    