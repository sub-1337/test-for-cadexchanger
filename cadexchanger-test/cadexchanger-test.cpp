#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include "curves.h"

int main() {
    constexpr double PI = 3.141592653589793;
    constexpr double t = PI / 4;

    // Container for curves
    std::vector<std::shared_ptr<Curve>> curves;
    
    // Populate curves with random parameters
    curves.push_back(std::make_shared<Circle>(5.0));
    curves.push_back(std::make_shared<Ellipse>(3.0, 4.0));
    curves.push_back(std::make_shared<Helix>(2.0, 1.0));
    curves.push_back(std::make_shared<Circle>(10.0));
    
    // Print points and derivatives at t=PI/4
    std::cout << "Points and derivatives at t=PI/4:\n";
    for (const auto& curve : curves) {
        Point3D point = curve->getPoint(t);
        Point3D derivative = curve->getDerivative(t);
        std::cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << ")"
            << " Derivative: (" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")\n";
    }

    // Filter only circles
    std::vector<std::shared_ptr<Circle>> circles;
    for (const auto& curve : curves) {
        auto circle = std::dynamic_pointer_cast<Circle>(curve);
        if (circle) {
            circles.push_back(circle);
        }
    }

    // Sort circles by radius
    std::sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {
        return a->getRadius() < b->getRadius();
        });

    // Compute the total sum of radii
    double totalRadius = 0.0;
    for (const auto& circle : circles) {
        totalRadius += circle->getRadius();
    }

    // Output results
    std::cout << "\nSorted Circles by Radius:\n";
    for (const auto& circle : circles) {
        std::cout << "Circle with radius: " << circle->getRadius() << "\n";
    }
    std::cout << "Total radius of all circles: " << totalRadius << "\n";
    
    return 0;
}