//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

TEST_F(WeatherTestCase, GetResponseForCityInvalidArgument) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 404;
    EXPECT_CALL(weather, Get("nonExistingCity")).WillOnce(testing::Return(mockResponse));

    ASSERT_THROW(weather.GetResponseForCity("nonExistingCity"), std::invalid_argument);
}

TEST_F(WeatherTestCase, GetResponseForCity) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 200;
    mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": 8}}]}";
    EXPECT_CALL(weather, Get("Moscow")).WillOnce(testing::Return(mockResponse));

    auto cityInfo = weather.GetResponseForCity("Moscow");
    auto answer = json::parse("{\"list\" : [{\"main\": {\"temp\": 8}}]}");
    ASSERT_EQ(cityInfo, answer);
}

TEST_F(WeatherTestCase, GetTemperature) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 200;
    mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": 29}}]}";
    EXPECT_CALL(weather, Get("Madrid")).WillOnce(testing::Return(mockResponse));

    ASSERT_EQ(weather.GetTemperature("Madrid"), 29);
}

TEST_F(WeatherTestCase, GetDifferenceStringPlus) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 200;
    mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": 8}}]}";
    EXPECT_CALL(weather, Get("Moscow")).WillRepeatedly(testing::Return(mockResponse));

    cpr::Response mockResponse2;
    mockResponse2.status_code = 200;
    mockResponse2.text = "{\"list\" : [{\"main\": {\"temp\": 29}}]}";
    EXPECT_CALL(weather, Get("Madrid")).WillRepeatedly(testing::Return(mockResponse2));

    std::string answer = "Weather in Madrid is warmer than in Moscow by 21 degrees";
    ASSERT_EQ(weather.GetDifferenceString("Madrid", "Moscow"), answer);
}

TEST_F(WeatherTestCase, GetDifferenceStringMinus) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 200;
    mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": 8}}]}";
    EXPECT_CALL(weather, Get("Moscow")).WillRepeatedly(testing::Return(mockResponse));

    cpr::Response mockResponse2;
    mockResponse2.status_code = 200;
    mockResponse2.text = "{\"list\" : [{\"main\": {\"temp\": 29}}]}";
    EXPECT_CALL(weather, Get("Madrid")).WillRepeatedly(testing::Return(mockResponse2));

    std::string answer = "Weather in Moscow is colder than in Madrid by 21 degrees";
    ASSERT_EQ(weather.GetDifferenceString("Moscow", "Madrid"), answer);
}

TEST_F(WeatherTestCase, FindDiffBetweenTwoCities) {
    WeatherMock weather;
    cpr::Response mockResponse;
    mockResponse.status_code = 200;
    mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": 8}}]}";
    EXPECT_CALL(weather, Get("Moscow")).WillRepeatedly(testing::Return(mockResponse));

    cpr::Response mockResponse2;
    mockResponse2.status_code = 200;
    mockResponse2.text = "{\"list\" : [{\"main\": {\"temp\": 29}}]}";
    EXPECT_CALL(weather, Get("Madrid")).WillRepeatedly(testing::Return(mockResponse2));

    ASSERT_EQ(weather.FindDiffBetweenTwoCities("Madrid", "Moscow"), 21);
    ASSERT_EQ(weather.FindDiffBetweenTwoCities("Moscow", "Madrid"), -21);
}

TEST_F(WeatherTestCase, SetApiKey) {
    ASSERT_NO_THROW(weather.SetApiKey("myApiKey"));
}
    