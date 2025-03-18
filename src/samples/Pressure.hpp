#ifndef __BASE_SAMPLES_PRESSURE_HPP
#define __BASE_SAMPLES_PRESSURE_HPP

#include <Pressure.hpp>
#include <Time.hpp>
#include <Float.hpp>

namespace base
{
    namespace samples
    {
        /** Timestamped pressure */
        struct Pressure : public base::Pressure
        {
            /** The sample timestamp */
            base::Time time;

            Pressure()
                : base::Pressure(base::Pressure::fromPascal(base::unknown<float>())) {}

            Pressure(base::Time const& _time, base::Pressure pressure)
                : base::Pressure(pressure)
                , time(_time) {}

            static Pressure fromPascal(base::Time const& _time, float pascal);

            static Pressure fromBar(base::Time const& _time, float bar);

            static Pressure fromPSI(base::Time const& _time, float psi);
        };
    }
}

#endif

