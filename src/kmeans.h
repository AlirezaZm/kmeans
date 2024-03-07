#pragma once
#include "base.h"

class Kmeans{
    Point centers;
    Point data_points;
public:
    Kmeans(Point&, Point&);
    void fit(int);
};