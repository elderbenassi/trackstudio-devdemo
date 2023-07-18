#pragma once
#include <list>
#include "Segment.h"

/// <summary>
/// This is a Track DTO which is a collection of segments
/// </summary>
class Track
{
private:
    int dbId;
    std::list<Segment> segments;
};
