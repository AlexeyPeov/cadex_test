#include "Helix.h"

namespace cdt
{

    Vec3d Helix::get_3d_point(double t) const
    {
        return Vec3d(
            m_radius * std::cos(t),
            m_radius * std::sin(t),
            m_step * t / (2 * cdt::PI));
    }

    Vec3d Helix::get_derivative(double t) const
    {
        return Vec3d(
            -m_radius * std::sin(t),
            m_radius * std::cos(t),
            m_step / (2 * cdt::PI));
    }

    void Helix::print_3d_point_and_derivative(double t) const
    {
        print("Helix", t);
    }

}