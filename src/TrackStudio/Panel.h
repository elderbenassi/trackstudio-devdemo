#pragma once
#include <string>
#include <list>
#include "Track.h"
#include "Composition.h"

/// <summary>
/// This class is the DTO for the Panel object, which contains the background image, the track and the train compositions
/// </summary>
class Panel
{
private:
    int dbId;
    std::string backgroundImage;
    Track track;
    std::list<Composition> compositions;
};