#pragma once
#include <string>
#include "LocomotiveModel.h"

/// <summary>
/// DTO for Locomotive, which is a special car with engine
/// </summary>
class Locomotive
{
private:
    int dbId;
    std::string serialNumber;
    LocomotiveModel locomotiveModel;
};

