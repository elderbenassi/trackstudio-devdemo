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

public:
    // Standard constructor
    Track() : dbId(0), segments() {}

    // Setting Constructor
    Track(int id, const std::list<Segment>& segmentList) : dbId(id), segments(segmentList)
    {      
    }

};
