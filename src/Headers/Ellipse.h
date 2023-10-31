#ifndef CADEX_TEST_ELLIPSE_H
#define CADEX_TEST_ELLIPSE_H

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

    class CURVES_EXPORT Ellipse : public Curve
    {
    public:
        Ellipse(double rX, double rY) : m_radius_x(rX), m_radius_y(rY)
        {
        }

        Vec3d get_3d_point(double t) const override;

        Vec3d get_derivative(double t) const override;

        void print_3d_point_and_derivative(double t) const override;

    private:
        double m_radius_x, m_radius_y;
    };

}
#endif