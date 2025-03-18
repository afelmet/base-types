#include "Acceleration.hpp"

namespace base {

Acceleration::Acceleration()
{
    setNaN();
}

Acceleration::Acceleration(base::Vector3d _linear, base::Vector3d _angular) :
    linear(_linear),
    angular(_angular)
{
}

void Acceleration::setNaN()
{
    linear.setConstant(std::numeric_limits<double>::quiet_NaN());
    angular.setConstant(std::numeric_limits<double>::quiet_NaN());
}

void Acceleration::setZero()
{
    linear.setZero();
    angular.setZero();
}

bool Acceleration::isValid() const
{
    return base::isnotnan(linear) && base::isnotnan(angular);
}

Acceleration operator+(const Acceleration& a, const Acceleration& b)
{
    return Acceleration(a.linear  + b.linear, a.angular + b.angular);
}

Acceleration operator-(const Acceleration& a, const Acceleration& b)
{
    return Acceleration(a.linear  - b.linear, a.angular - b.angular);
}

}
