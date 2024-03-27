#include "Eagle.h"

double Eagle::DistRF() {
    return (distance * 0.06);
}
Eagle::Eagle(int distance) {
    this->distance = distance;
    this->name = "Орел";
    this->speed = 8;
    this->time = (distance - DistRF()) / speed;
}
