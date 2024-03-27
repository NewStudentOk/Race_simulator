#pragma once
#include "Air_vehicles.h"

class Broom : public Air_vehicles{
public:
    Broom(int distance);
    double DistRF(); //коэффициент сокращения расстояния
};