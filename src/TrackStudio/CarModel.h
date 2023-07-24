#pragma once
#include <string>
#include "RollingStock.h"

/// <summary>
/// CarType enum that describes its use
/// </summary>
enum CarType
{
    FLATBED,
    BOX_WAGON,
    TANKER,
    HOPPER,
    PASSENGER_WAGON,
    NON_REVENUE
};

/// <summary>
/// CarModel DTO class, inherit from RollingStock
/// </summary>
class CarModel : public RollingStock
{
private:
    std::string modelName;
    CarType carType;
};
