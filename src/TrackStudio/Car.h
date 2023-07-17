#pragma once
#include <string>
#include <list>
#include "Cargo.h"
#include "CarModel.h"

class Car
{
private:
    int dbId;
    std::string serialNumber;
    CarModel carModel;
    std::list<Cargo> cargos;
};
