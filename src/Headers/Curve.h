#ifndef CADEX_TEST_CURVE_H
#define CADEX_TEST_CURVE_H

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

#include <iostream>
#include <string>

#include "Vec3d.h"
#include "Constants.h"

namespace cdt
{

    class CURVES_EXPORT Curve
    {
    public:
        virtual ~Curve() {}
        virtual Vec3d get_3d_point(double t) const = 0;
        virtual Vec3d get_derivative(double t) const = 0;
        virtual void print_3d_point_and_derivative(double t) const = 0;

        void print(const std::string &obj_name, double t) const;
    };

}

#endif