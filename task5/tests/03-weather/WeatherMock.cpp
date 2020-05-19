//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherMock.h"

cpr::Response WeatherMock::Get(const std::string& city) {
    cpr::Response mockResponse;

    if (city == "nonExistingCity") {
        mockResponse.status_code = 404;
        return mockResponse;
    }

    mockResponse.status_code = 200;

    if (city == "Moscow") {
        mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": 8}}]}";
    }
    else {
        mockResponse.text = "{\"list\" : [{\"main\": {\"temp\": 29}}]}";
    }

    return mockResponse;
}
