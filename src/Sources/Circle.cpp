#include "Circle.h"


namespace cdt
{
    Vec3d Circle::get_3d_point(double t) const
    {
        return Vec3d(
            m_radius * std::cos(t),
            m_radius * std::sin(t),
            0);
    }

    Vec3d Circle::get_derivative(double t) const
    {
        return Vec3d(
            -m_radius * std::sin(t),
            m_radius * std::cos(t),
            0);
    }

    void Circle::print_3d_point_and_derivative(double t) const
    {
        print("Circle", t);
    }
}