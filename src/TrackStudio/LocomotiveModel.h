#pragma once
#include <string>
#include "RollingStock.h"

enum FuelType
{
    GAS,
    DIESEL,
    ELECTRIC
};

class LocomotiveModel : public RollingStock
{
private:
    std::string modelName;
    std::string engineName;
    int enginePower;
    FuelType fuelType;
};

