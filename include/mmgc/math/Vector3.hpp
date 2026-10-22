#pragma once
#include <cmath>

namespace mmgc::math {
struct Vector3 {
    double x{}, y{}, z{};
    constexpr Vector3() = default;
    constexpr Vector3(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}
    constexpr Vector3 operator+(const Vector3& v) const { return {x+v.x,y+v.y,z+v.z}; }
    constexpr Vector3 operator-(const Vector3& v) const { return {x-v.x,y-v.y,z-v.z}; }
    constexpr Vector3 operator*(double s) const { return {x*s,y*s,z*s}; }
    constexpr Vector3 operator/(double s) const { return {x/s,y/s,z/s}; }
    constexpr Vector3& operator+=(const Vector3& v) { x+=v.x; y+=v.y; z+=v.z; return *this; }
    double magnitude() const { return std::sqrt(x*x+y*y+z*z); }
    double magnitudeSquared() const { return x*x+y*y+z*z; }
    static constexpr double dot(const Vector3& a,const Vector3& b){return a.x*b.x+a.y*b.y+a.z*b.z;}
    static constexpr Vector3 cross(const Vector3& a,const Vector3& b){return {a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};}
};
}
