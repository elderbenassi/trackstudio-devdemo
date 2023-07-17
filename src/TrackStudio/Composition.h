#pragma once
#include <list>
#include "Locomotive.h"
#include "Car.h"

class Composition
{
private:
    int dbId;
    std::list<Locomotive> locomotives;
    std::list<Car> cars;
};
