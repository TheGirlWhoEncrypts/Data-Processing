#include "Point2D.h"

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

/* 
    - Computes the distance of the point to the orgin (0, 0) + 
    - Initialize the attribute distFrOrgin with this COMPUTED distance value
*/
void Point2D::setDistFrOrigin() { this->distFrOrigin = sqrt(pow(x, 2) + pow(y, 2)); }

Point2D::Point2D(int x, int y)
{
    this->x = x;
    this->y = y;
    setDistFrOrigin();
}

int Point2D::getX() const { return this->x; }
int Point2D::getY() const { return this->y; }

// Return the value attribute distFrOrigin
double Point2D::getScalarValue() const { return this->distFrOrigin; }

void Point2D::setX(int x) { this->x = x; }
void Point2D::setY(int y) { this->y = y; }

// Operator Overloading
bool Point2D::operator<(const Point2D &rhs) const { return (this->x < rhs.x || this->y < rhs.y); }
bool Point2D::operator==(const Point2D &rhs) const { return ((this->x == rhs.x) && (this->y == rhs.y)); }

// Friend Function
ostream &operator<<(ostream &out, const Point2D &point2D)
{
    out << Formatter::format2DCoordinates(point2D.getX(), point2D.getY());
    out << Formatter::addSpacing(3);
    out << Formatter::formatDistance(point2D.getScalarValue());
    return out;
}
