#include "Temperature.hpp"

namespace base { namespace samples{

    Temperature Temperature::fromKelvin(base::Time const& _time, double kelvin)
    {
        return Temperature(_time, base::Temperature::fromKelvin(kelvin));
    }

    Temperature Temperature::fromCelsius(base::Time const& _time, double celsius)
    {
        return Temperature(_time, base::Temperature::fromCelsius(celsius));
    }

} } //end namespace base::samples
