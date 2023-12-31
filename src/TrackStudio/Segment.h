#pragma once
#include "Waypoint.h"

/// <summary>
/// This is a DTO class for a Segment, which is a streght line between two waypoints in a cartesian space
/// </summary>
class Segment
{
private:
    int dbId;
    Waypoint startPoint;
    Waypoint endPoint;
};
