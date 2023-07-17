#pragma once
#include <string>

enum CargoType
{
    INERT,
    FLAMMABLE,
    FOOD_GRADE,
    TOXIC,
    EMPTY,
    PASSENGER
};

class Cargo
{
private:
    int dbId;
    std::string description;
    float weight;
    CargoType cargoType;
};
