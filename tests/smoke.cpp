#include <cassert>
#include "mmgc/math/Vector3.hpp"
#include "mmgc/physics/OrbitalMechanics.hpp"

int main() {
    using mmgc::math::Vector3;
    const Vector3 a{3,4,0};
    assert(a.magnitude() == 5.0);
    const auto acc = mmgc::physics::two_body_acceleration({7.0e6,0,0}, 3.986004418e14);
    assert(acc.x < 0.0);
    return 0;
}
