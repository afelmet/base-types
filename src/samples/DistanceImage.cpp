#include "DistanceImage.hpp"

#include <limits>
#include <Eigen/Core>

namespace base { namespace samples {

void DistanceImage::clear()
{
    std::fill( data.begin(), data.end(), std::numeric_limits<scalar>::quiet_NaN() );
}

Pointcloud DistanceImage::getPointCloud() const
{
    Pointcloud pointCloud;
    pointCloud.time = time;
    Eigen::Vector3d point;
    for(size_t y = 0; y < this->height ; ++y)
    {
        for(size_t x = 0; x < this->width ; ++x)
        {
            if (this->getScenePoint(x, y, point))
            {
                pointCloud.points.push_back(point);
            }
        }
    }
    return pointCloud;
}

void DistanceImage::setIntrinsic(float f_x, float f_y, float c_x, float c_y)
{
    scale_x = 1.0f / f_x;
    scale_y = 1.0f / f_y;
    center_x = -c_x / f_x;
    center_y = -c_y / f_y;
}

void DistanceImage::setSize(uint16_t _width, uint16_t _height)
{
    this->width = _width;
    this->height = _height;
    data.resize( static_cast<size_t>(_width) * static_cast<size_t>(_height));
}

}} //end namespace base::samples
