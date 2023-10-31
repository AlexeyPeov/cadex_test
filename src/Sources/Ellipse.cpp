#include "Ellipse.h"
namespace cdt
{
    Vec3d Ellipse::get_3d_point(double t) const
    {
        return Vec3d(
            m_radius_x * std::cos(t),
            m_radius_y * std::sin(t),
            0);
    }

    Vec3d Ellipse::get_derivative(double t) const
    {
        return Vec3d(
            -m_radius_x * std::sin(t),
            m_radius_y * std::cos(t),
            0);
    }

    void Ellipse::print_3d_point_and_derivative(double t) const
    {
        print("Ellipse", t);
    }
}