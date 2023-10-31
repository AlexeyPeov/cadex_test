#ifndef CADEX_TEST_VEC3D_H
#define CADEX_TEST_VEC3D_H

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

namespace cdt
{

    class CURVES_EXPORT Vec3d
    {
    public:
        Vec3d(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {}

        double x() { return m_x; }
        double y() { return m_y; }
        double z() { return m_z; }

    private:
        double m_x = 0.0;
        double m_y = 0.0;
        double m_z = 0.0;
    };

}
#endif