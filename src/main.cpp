#include <iostream>
#include "base.h"
#include "kmeans.h"

int main()
{
    Point data_points = generate_random_point(3, 50, 10);
    Point centers = generate_random_center(3);
    Kmeans kmeans(data_points, centers);
    kmeans.fit(10);
}
