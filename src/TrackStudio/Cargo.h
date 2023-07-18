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

/// <summary>
/// DTO class for cargo, which is the payload transported by cars
/// </summary>
class Cargo
{
private:
    int dbId;
    std::string description;
    float weight;
    CargoType cargoType;
};
