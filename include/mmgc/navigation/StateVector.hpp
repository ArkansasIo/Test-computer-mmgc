#pragma once
#include "mmgc/math/Vector3.hpp"

namespace mmgc::navigation {
struct StateVector {
    math::Vector3 position_m;
    math::Vector3 velocity_mps;
    double mass_kg{0.0};
    double mission_time_s{0.0};
};
}
