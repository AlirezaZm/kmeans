#include "base.h"

#include <random>
#include <limits>

void Point::push(float x_point, float y_point)
{
    if (index < size)
    {
        x[index] = x_point;
        y[index] = y_point;
        index++;
        return;
    }
    std::cout << "overflow from initial size,reallocating...";
    x.push_back(x_point);
    y.push_back(y_point);
}
void Point::print()
{
    for (int i = 0; i < get_size(); i++)
    {
        std::cout << "[" << x[i] << "," << y[i] << "]"
                  << ",\n";
    }
}
void Point::zeros()
{
    for (int i = 0; i < get_size(); ++i)
    {
        x[i] = 0;
        y[i] = 0;
    }
}
void Point::biggest()
{
    for (int i = 0; i < get_size(); ++i)
    {
        x[i] = std::numeric_limits<float>::max();
        y[i] = std::numeric_limits<float>::max();
    }
}
FloatVec Point::get_index(int index)
{
    std::vector<float> res = {x[index], y[index]};
    return res;
}
size_t Point::get_size()
{
    return size;
}
Point generate_random_point(int num_cluster, int point_per_cluster, int cluster_spread, int min, int max)
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    Point centers(num_cluster);
    Point data_points(num_cluster * point_per_cluster);
    for (int i = 0; i < num_cluster; ++i)
    {
        centers.push(dis(gen), dis(gen));
        std::uniform_real_distribution<> spread(0, cluster_spread);
        for (int j = 0; j < point_per_cluster; ++j)
        {
            data_points.push(spread(gen) + centers.x[i], spread(gen) + centers.y[i]);
        }
    }
    return data_points;
}
Point generate_random_center(int num_cluster, int min, int max)
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    Point centers(num_cluster);
    for (int i = 0; i < num_cluster; ++i)
        centers.push(dis(gen), dis(gen));
    return centers;
}
