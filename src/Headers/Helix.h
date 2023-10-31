#ifndef CADEX_TEST_HELIX_H
#define CADEX_TEST_HELIX_H

#if defined(_WIN32)
#ifdef _MSC_VER
#pragma warning(disable: 4251)
#endif
#if defined(curves_EXPORT)
#define CURVES_EXPORT __declspec(dllexport)
#else
#define CURVES_EXPORT __declspec(dllimport)
#endif
#else
#define CURVES_EXPORT
#endif

#include "Curve.h"

namespace cdt
{
    class CURVES_EXPORT Helix : public Curve
    {
    public:
        Helix(double r, double step) : m_radius(r), m_step(step) {}

        Vec3d get_3d_point(double t) const override;

        Vec3d get_derivative(double t) const override;

        void print_3d_point_and_derivative(double t) const override;

    private:
        double m_radius, m_step;
    };
}
#endif