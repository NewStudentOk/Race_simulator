#include "Magic_carpet.h"

double Magic_carpet::DistRF() {
    if (distance < 1000) {
        return distance;
    } else if (distance < 5000) {
        return (distance * 0.03);
    } else if (distance < 10000) {
        return (distance * 0.1);
    } else if (distance >= 10000) {
        return (distance * 0.05);
    }
    return 0;
}

Magic_carpet::Magic_carpet(int distance) {
    this->distance = distance;
    this->name = "Ковер-самолет";
    this->speed = 10;
    this->time = (distance - DistRF()) / speed;
}