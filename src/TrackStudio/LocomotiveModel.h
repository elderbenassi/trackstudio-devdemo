#pragma once
#include <string>
#include "RollingStock.h"

/// <summary>
/// Types of fuels used by locomotives
/// </summary>
enum FuelType
{
    GAS,
    DIESEL,
    ELECTRIC
};

/// <summary>
/// DTO for Locomotive Models, inherit from RollingStock
/// </summary>
class LocomotiveModel : public RollingStock
{
private:
    std::string modelName;
    std::string engineName;
    int enginePower;
    FuelType fuelType;
};

