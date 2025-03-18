#include "Motion2D.hpp"

namespace base { namespace commands {

bool operator==(const Motion2D& lhs, const Motion2D& rhs)
{
    return fabs(lhs.translation - rhs.translation) < 1e-5 && fabs(lhs.rotation - rhs.rotation) < 1e-5 && lhs.heading == rhs.heading;
}

bool operator!=(const Motion2D& lhs, const Motion2D& rhs)
{
    return !(lhs == rhs);
}

}} // end namespace base::commands

