#pragma once
#include "Panel.h"

/// <summary>
/// Singleton class of Panel
/// </summary>
class PanelSingleton
{
private:
    PanelSingleton() = default;
    static Panel* instance; 

public:
    static Panel* getInstance();
        
    // Prevent other instances of Panel
    //PanelSingleton(const PanelSingleton&) = delete;
    //PanelSingleton& operator=(const PanelSingleton&) = delete;
};
