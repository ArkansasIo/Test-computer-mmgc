#pragma once
#include "mmgc/navigation/StateVector.hpp"

namespace mmgc::guidance {
struct GuidanceCommand { math::Vector3 delta_v_mps{}; bool valid{false}; };

class GuidanceComputer {
public:
    GuidanceCommand minimumImpulse(const navigation::StateVector& state,
                                   const math::Vector3& target_position_m) const;
};
}
