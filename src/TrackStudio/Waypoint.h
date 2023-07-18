#pragma once
#include <string>

/// <summary>
/// This class is the DTO for waypoints, which are locations in a space to form segments
/// </summary>
class Waypoint
{
private:
    int dbId;
    int xCoordinate;
    int yCoordinate;
    std::string locationName;
};
