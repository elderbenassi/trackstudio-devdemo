#pragma once
#include <list>
#include "Segment.h"

class Track
{
private:
    int dbId;
    std::list<Segment> segments;
};
