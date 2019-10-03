#include "Point3D.h"
#include "formatter.h"

#include <iostream>
#include <cmath>

using namespace std;
/* 
- Computes the distance of the point to the orgin (0, 0, 0) + 
- Initialize the attribute distFrOrgin with this COMPUTED distance value
*/
void Point3D::setDistFrOrigin() { Point2D::distFrOrigin = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)); }

Point3D::Point3D(int x, int y, int z) : Point2D(x, y)
{
    this->z = z;
    setDistFrOrigin();
}

int Point3D::getZ() const { return this->z; }
void Point3D::setZ(int z) { this->z = z; }

// Operator Overloading
bool Point3D::operator<(const Point3D &rhs) const { return (Point2D::operator<(rhs) || this->z < rhs.z); }
bool Point3D::operator==(const Point3D &rhs) const { return (Point2D::operator==(rhs) && this->z == rhs.z); }

// Friend Function
ostream &operator<<(ostream &out, const Point3D &point3D)
{
    out << Formatter::format3DCoordinates(point3D.getX(), point3D.getY(), point3D.getZ());
    out << Formatter::addSpacing(3);
    out << Formatter::formatDistance(point3D.getScalarValue());
    return out;
}