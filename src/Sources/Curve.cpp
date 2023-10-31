#include "Curve.h"
namespace cdt
{
        void Curve::print(const std::string &obj_name, double t) const {
                auto point = get_3d_point(t);
                auto der = get_derivative(t);
                std::cout << obj_name <<  " at t = " << t << " rad (" << t*180/cdt::PI << "deg)"
                        <<"\n\t3d point:"
                        "\n\tx: " << point.x() << 
                        "\n\ty: " << point.y() <<
                        "\n\tz: " << point.z() << 
                        "\n\n\tderivative:" <<
                        "\n\tx: " << der.x() << 
                        "\n\ty: " << der.y() <<
                        "\n\tz: " << der.z() << 
                        "\n\n";
        }
}