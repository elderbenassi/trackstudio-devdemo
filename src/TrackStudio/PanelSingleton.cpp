#include "pch.h"
#include "PanelSingleton.h"

Panel* PanelSingleton::instance = nullptr;

/// <summary>
/// Get the singleton instance of Panel object
/// </summary>
/// <returns></returns>
Panel* PanelSingleton::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Panel(); 
    }
    return instance;
}