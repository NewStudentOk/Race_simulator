#pragma once

#include "Vehicles.h"

class Land_vehicles : public Vehicles {
protected:
    double pause_time = 0.0;
    double pause_distance = 0.0;
    int pause_count = 0;
public:
    Land_vehicles();

};
