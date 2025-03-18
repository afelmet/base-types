// Copyright 2020 Rock-Core
#include "OrientedBoundingBox.hpp"

namespace base {
namespace samples {

OrientedBoundingBox::OrientedBoundingBox(const Time& _time,
                                         const Vector3d& _position,
                                         const Vector3d& _dimension,
                                         const Orientation& _orientation) {
    initOrientedBoundingBox(_time, _position, _dimension, _orientation);
}

void OrientedBoundingBox::initOrientedBoundingBox(const Time& _time,
                                                  const Vector3d& _position,
                                                  const Vector3d& _dimension,
                                                  const Orientation& _orientation) {
    initBoundingBox(_time, _position, _dimension);
    this->orientation = _orientation;
    this->cov_orientation = Matrix3d::Ones() * unknown<double>();
}

bool OrientedBoundingBox::hasValidBoundingBox() const {
    return BoundingBox::hasValidBoundingBox() && hasValidOrientation();
}

bool OrientedBoundingBox::hasValidOrientation() const {
    return orientation.toRotationMatrix().allFinite();
}

bool OrientedBoundingBox::hasValidCovariance() const {
    return BoundingBox::hasValidCovariance() && hasValidCovOrientation();
}

bool OrientedBoundingBox::hasValidCovOrientation() const {
    return cov_orientation.allFinite();
}

}  // namespace samples
}  // namespace base
