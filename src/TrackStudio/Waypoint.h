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

public:
    // Standard Constructor
    Waypoint()
        :dbId(0), xCoordinate(0), yCoordinate(0), locationName("")
    {

    }

    // Setting Constructor
    Waypoint(int id, int x, int y, const std::string& name)
        : dbId(id), xCoordinate(x), yCoordinate(y), locationName(name)
    {
    }

    int GetId()
    {
        return dbId;
    }
};
