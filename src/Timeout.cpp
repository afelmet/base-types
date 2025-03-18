#include "Timeout.hpp"

namespace base {

Timeout::Timeout(Time _timeout) : timeout(_timeout)
{
    start_time = Time::now();
}

void Timeout::restart()
{
    start_time = Time::now();
}

bool Timeout::elapsed() const
{
    return elapsed(timeout);
}

bool Timeout::elapsed(const Time& _timeout) const
{
    if(!_timeout.isNull())
    {
        return start_time + _timeout < Time::now();
    }
    else
    {
        return false;
    }
}

Time Timeout::timeLeft() const
{
    return timeLeft(timeout);
}

Time Timeout::timeLeft(const Time& _timeout) const
{
    if(!_timeout.isNull())
    {
        return start_time + _timeout - Time::now();
    }
    else
    {
        return Time::max();
    }
}


} //end namespace base


