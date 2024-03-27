#pragma once
#include <string>

class Vehicles {
protected:
    std::string name;
    int type_of_transport = 0;
    double speed = 0.0;
    int distance = 0;
    double time = 0.0;
public:
    Vehicles();

    std::string GetName();

    double Time();

    int TypeOfTransport();

};