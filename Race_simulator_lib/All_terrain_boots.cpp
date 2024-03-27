#include "All_terrain_boots.h"

All_terrain_boots::All_terrain_boots(int distance) {
    this->distance = distance;
    this->name = "Ботинки-вездеходы";

    this->speed = 6;
    this->pause_distance = 60;

    this->pause_count = static_cast<int>((distance / speed) / pause_distance);
    this->pause_time = 10 + (pause_count - 1) * 5;

    this->time = (distance / speed) + pause_time;
}
