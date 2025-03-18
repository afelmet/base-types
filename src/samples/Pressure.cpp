#include "Pressure.hpp"

namespace base { namespace samples {

Pressure Pressure::fromPascal(const Time& _time, float pascal)
{
    return Pressure(_time, base::Pressure::fromPascal(pascal));
}

Pressure Pressure::fromBar(const Time& _time, float bar)
{
    return Pressure(_time, base::Pressure::fromBar(bar));
}

Pressure Pressure::fromPSI(const Time& _time, float psi)
{
    return Pressure(_time, base::Pressure::fromPSI(psi));
}

}} //end namespace base::samples
