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
    int _dbId;
    std::string _backgroundImage;
    Track _track;
    std::list<Composition> _compositions;
public:
    // Standard constructor
    Panel() : _dbId(0), _backgroundImage(""), _track(), _compositions() {}

    void SetTrack(Track track)
    {
        _track = track;
    }
};