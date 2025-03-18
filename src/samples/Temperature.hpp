#ifndef __BASE_SAMPLES_TEMPERATURE_HH__
#define __BASE_SAMPLES_TEMPERATURE_HH__

#include <Temperature.hpp>
#include <Time.hpp>

namespace base
{
    namespace samples
    {
        struct Temperature : public base::Temperature
        {
            /** The sample timestamp */
            base::Time time;

            Temperature() : base::Temperature() { }

            Temperature(base::Time const& _time, base::Temperature temp)
                : base::Temperature(temp.getKelvin())
                , time(_time) { }

            static Temperature fromKelvin(base::Time const& _time, double kelvin);

            static Temperature fromCelsius(base::Time const& _time, double celsius);

        };
    }
}

#endif
