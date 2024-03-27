#include "Vehicles.h"

Vehicles::Vehicles() {}

std::string Vehicles::GetName() {
    return name;
}

double Vehicles::Time() {
    return time;
}

int Vehicles::TypeOfTransport() {
    return this->type_of_transport;
}