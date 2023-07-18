#pragma once
#include <list>
#include "Locomotive.h"
#include "Car.h"

/// <summary>
/// Composition DTO, which is a set of locomotives and cars
/// </summary>
class Composition
{
private:
    int dbId;
    std::list<Locomotive> locomotives;
    std::list<Car> cars;
};
