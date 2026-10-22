#include "mmgc/guidance/GuidanceComputer.hpp"

namespace mmgc::guidance {
GuidanceCommand GuidanceComputer::minimumImpulse(const navigation::StateVector& state,
                                                  const math::Vector3& target_position) const {
    const auto error = target_position - state.position_m;
    if (error.magnitudeSquared() == 0.0) return {};
    const double gain = 1.0e-3;
    return {error * gain, true};
}
}
