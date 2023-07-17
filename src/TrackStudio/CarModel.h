#pragma once
#include <string>
#include "RollingStock.h"

enum CarType
{
    FLATBED,
    BOX_WAGON,
    TANKER,
    HOPPER,
    PASSENGER,
    NON_REVENUE
};

class CarModel : public RollingStock
{
private:
    std::string modelName;
    CarType carType;
};
