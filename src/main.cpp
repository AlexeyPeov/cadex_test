#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#include <omp.h>

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"


int main()
{

    srand(time(nullptr));

    std::vector<std::unique_ptr<cdt::Curve>> curves;

    for (int i = 0; i < 10; ++i)
    {
        switch (rand() % 3)
        {
        case 0:
            curves.emplace_back(
                std::make_unique<cdt::Circle>(rand() % 100 + 1)
            );
            break;
        case 1:
            curves.emplace_back(
                std::make_unique<cdt::Ellipse>(rand() % 100 + 1, rand() % 100 + 1)
            );
            break;
        case 2:
            curves.emplace_back(
                std::make_unique<cdt::Helix>(rand() % 100 + 1, rand() % 100 + 1)
            );
            break;
        }
    }

    
    for (const auto &curve : curves)
    {
        curve->print_3d_point_and_derivative(cdt::PI / 4);
    }


    std::vector<cdt::Circle*> circles;
    for (const auto &curve : curves)
    {
        if (const auto c = dynamic_cast<cdt::Circle *>(curve.get()); c != nullptr)
        {
            circles.emplace_back(c);
        }
    }


    std::sort(circles.begin(), circles.end(), [](cdt::Circle *a, cdt::Circle *b)
              { return a->getRadius() < b->getRadius(); });


    double totalRadius = 0.0;
    #pragma omp parallel for reduction(+:totalRadius)
    for (const auto &circle : circles)
    {
        totalRadius += circle->getRadius();
    }

    std::cout << "Total sum of radii: " << totalRadius << std::endl;


    return 0;
}
