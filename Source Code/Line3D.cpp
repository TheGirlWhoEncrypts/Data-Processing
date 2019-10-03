#include "Line3D.h"

#include <iostream>
#include <cmath>

using namespace std;

void Line3D::setLength()
{
    Line2D::length = sqrt(pow((pt1.getX() - pt2.getX()), 2) + pow((pt1.getY() - pt2.getY()), 2) + pow((pt1.getZ() - pt2.getZ()), 2));
}

Line3D::Line3D()
{
    this->pt1 = Point3D();
    this->pt2 = Point3D();
}

Line3D::Line3D(Point3D pt1, Point3D pt2) : pt1(pt1), pt2(pt2) { setLength(); }

Point3D Line3D::getPt1() const { return pt1; }
Point3D Line3D::getPt2() const { return pt2; }

void Line3D::setPt1(Point3D pt1) { this->pt1 = pt1; }
void Line3D::setPt2(Point3D pt2) { this->pt2 = pt2; }

// Operator Overloading
bool Line3D::operator<(const Line3D &rhs) const { return ((this->pt1 < rhs.pt1) || (this->pt2 < rhs.pt2)); }
bool Line3D::operator==(const Line3D &rhs) const { return ((this->pt1 == rhs.pt1) && (this->pt2 == rhs.pt2)); }

// Friend Function
ostream &operator<<(ostream &out, const Line3D &line3D)
{
    out << Formatter::format3DCoordinates(line3D.getPt1().getX(), line3D.getPt1().getY(), line3D.getPt1().getZ());
    out << Formatter::addSpacing(3);
    out << Formatter::format3DCoordinates(line3D.getPt2().getX(), line3D.getPt2().getY(), line3D.getPt2().getZ());
    out << Formatter::addSpacing(3);
    out << Formatter::formatDistance(line3D.getScalarValue());
    return out;
}