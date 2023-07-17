#pragma once
#include <string>
#include <list>
#include "Track.h"
#include "Composition.h"

class Panel
{
private:
    int dbId;
    std::string backgroundImage;
    Track track;
    std::list<Composition> compositions;
};
