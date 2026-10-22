#include <iostream>
#include "mmgc/guidance/GuidanceComputer.hpp"
#include "mmgc/physics/OrbitalMechanics.hpp"

int main() {
    mmgc::navigation::StateVector state;
    state.position_m = {7.0e6, 0.0, 0.0};
    state.velocity_mps = {0.0, 7546.0, 0.0};
    state.mass_kg = 1000.0;

    const double mu_earth = 3.986004418e14;
    const auto acceleration = mmgc::physics::two_body_acceleration(state.position_m, mu_earth);
    const auto command = mmgc::guidance::GuidanceComputer{}.minimumImpulse(state, {7.1e6, 0.0, 0.0});

    std::cout << "MMGC 0.1.0\n"
              << "Earth acceleration: " << acceleration.x << ", " << acceleration.y << ", " << acceleration.z << " m/s^2\n"
              << "Guidance command valid: " << std::boolalpha << command.valid << "\n";
    return 0;
}
