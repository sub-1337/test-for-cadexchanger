#ifndef CURVES_H
#define CURVES_H

#include <cmath>
#include <vector>
#include <memory>

struct Point3D {
    double x, y, z;
};

class Curve {
public:
    virtual ~Curve() = default;
    virtual Point3D getPoint(double t) const = 0;
    virtual Point3D getDerivative(double t) const = 0;
};

class Circle : public Curve {
public:
    Circle(double radius) : radius(radius) {}
    Point3D getPoint(double t) const override;
    Point3D getDerivative(double t) const override;
    double getRadius() const { return radius; }

private:
    double radius;
};

class Ellipse : public Curve {
public:
    Ellipse(double a, double b) : a(a), b(b) {}
    Point3D getPoint(double t) const override;
    Point3D getDerivative(double t) const override;

private:
    double a, b;
};

class Helix : public Curve {
public:
    Helix(double radius, double step) : radius(radius), step(step) {}
    Point3D getPoint(double t) const override;
    Point3D getDerivative(double t) const override;

private:
    double radius, step;
};

#endif // CURVES_H#pragma once
