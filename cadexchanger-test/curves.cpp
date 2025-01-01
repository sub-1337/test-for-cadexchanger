#include "curves.h"

// Circle Implementation
Point3D Circle::getPoint(double t) const {
    return { radius * std::cos(t), radius * std::sin(t), 0.0 };
}

Point3D Circle::getDerivative(double t) const {
    return { -radius * std::sin(t), radius * std::cos(t), 0.0 };
}

// Ellipse Implementation
Point3D Ellipse::getPoint(double t) const {
    return { a * std::cos(t), b * std::sin(t), 0.0 };
}

Point3D Ellipse::getDerivative(double t) const {
    return { -a * std::sin(t), b * std::cos(t), 0.0 };
}

// Helix Implementation
Point3D Helix::getPoint(double t) const {
    return { radius * std::cos(t), radius * std::sin(t), step * t };
}

Point3D Helix::getDerivative(double t) const {
    return { -radius * std::sin(t), radius * std::cos(t), step };
}