#include "kmeans.h"

#include <math.h>

Kmeans::Kmeans(Point &data_input, Point &centers_input) : data_points(data_input), centers(centers_input)
{
}
std::vector<float> min_dist_calculate(std::vector<float> *x, std::vector<float> *y, FloatVec center, size_t size)
{
    std::vector<float> result(size);
    for (int i = 0; i < size; ++i)
    {
        float x_dist = (*x)[i] - center[0];
        float y_dist = (*y)[i] - center[1];
        result[i] = ((x_dist * x_dist) + (y_dist * y_dist));
    }
    return result;
}
void nearest_index(Point &data_points, Point &centers, Point &nearest_result, size_t size)
{
    nearest_result.biggest();
    for (int i = 0; i < centers.get_size(); ++i)
    {
        FloatVec center = centers.get_index(i);
        std::vector<float> result = min_dist_calculate(&data_points.x, &data_points.y, center, size);
        for (int j = 0; j < size; j++)
        {
            if (result[j] < nearest_result.x[j])
            {
                nearest_result.x[j] = result[j];
                nearest_result.y[j] = i;
            }
        }
    }
}
void Kmeans::fit(int epochs)
{
    size_t size = data_points.get_size();
    Point new_centers(centers.get_size());
    Point nearest_result(size);
    for (int epoch = 0; epoch < epochs; epoch++)
    {
        int cluster_size = 0;
        new_centers.zeros();
        nearest_index(data_points, centers, nearest_result, size);
        for (int j = 0; j < size; j++)
        {
            new_centers.x[nearest_result.y[j]] = data_points.x[j];
            new_centers.y[nearest_result.y[j]] = data_points.y[j];
        }
        centers = new_centers;
    }
}