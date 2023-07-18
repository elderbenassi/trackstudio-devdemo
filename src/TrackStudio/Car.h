#pragma once
#include <string>
#include <list>
#include "Cargo.h"
#include "CarModel.h"

/// <summary>
/// DTO for Car class
/// </summary>
class Car
{
private:
    int dbId;
    std::string serialNumber;
    CarModel carModel;
    std::list<Cargo> cargos;
};
