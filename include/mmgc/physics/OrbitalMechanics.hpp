#pragma once
#include "mmgc/math/Vector3.hpp"

namespace mmgc::physics {
inline constexpr double G = 6.67430e-11;

inline math::Vector3 two_body_acceleration(const math::Vector3& r, double mu) {
    const double r2 = r.magnitudeSquared();
    const double rmag = std::sqrt(r2);
    if (rmag == 0.0) return {};
    return r * (-mu / (r2 * rmag));
}
}
