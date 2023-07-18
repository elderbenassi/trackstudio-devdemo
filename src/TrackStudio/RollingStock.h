#pragma once

/// <summary>
/// DTO class of RollingStock, that is, all assets in a rail system that has steel wheels
/// </summary>
class RollingStock
{
protected:
    int dbId;
    int metricGauge;
    int metricGrossWeight;
    int axleQuantity;
    bool giveCoupling;
    bool acceptCoupling;
};
