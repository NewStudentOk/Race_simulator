#include "Broom.h"

double Broom::DistRF()
{
    int distRed = (distance / 1000);
    return static_cast<double>(distance * distRed / 100);

}
Broom::Broom(int distance)
{
    this->distance = distance;
    this->name = "Метла";

    this->speed = 20;

    this->time = (distance - DistRF()) / speed;

}
