#pragma once

#include <cstddef>
#include <vector>
#include <iostream>
#include <vector>

using FloatVec = std::vector<float>;

class Point
{
public:
    int index = 0;
    size_t size;
    std::vector<float> x;
    std::vector<float> y;
    Point(size_t size) : x(size), y(size), size(size) {}
    void push(float x_point, float y_point);
    void print();
    size_t get_size();
    void zeros();
    void biggest();
    std::vector<float> get_index(int index);
};
Point generate_random_point(int num_cluster, int point_per_cluster, int cluster_spread, int min = 0, int max = 100);
Point generate_random_center(int num_cluster, int min = 0, int max = 100);
