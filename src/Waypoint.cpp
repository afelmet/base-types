// Copyright 2020 Rock-Core
#include "Waypoint.hpp"

namespace base {

Waypoint::Waypoint()
    : position(Position::Identity()),
      heading(0),
      tol_position(0),
      tol_heading(0) {
}

Waypoint::Waypoint(base::Vector3d const& _position,
                   double _heading)
    : position(_position),
      heading(_heading),
      tol_position(0),
      tol_heading(0) {
}

Waypoint::Waypoint(base::Vector3d const& _position,
                   double _heading,
                   double _tol_position,
                   double _tol_heading)
    : position(_position),
      heading(_heading),
      tol_position(_tol_position),
      tol_heading(_tol_heading) {
}

Waypoint::Waypoint(Eigen::Vector3d const& _position,
                   double _heading,
                   double _tol_position,
                   double _tol_heading)
    : position(_position),
      heading(_heading),
      tol_position(_tol_position),
      tol_heading(_tol_heading) {
}

bool Waypoint::hasValidPosition() const {
    return position.allFinite();
}

}  // namespace base
