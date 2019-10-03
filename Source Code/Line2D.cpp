#include "Line2D.h"

#include <iostream>
#include <cmath>

using namespace std;
/* 
- Computes the distance between its own Point2D attributes pt1 and pt2
- Initializes the attribute length with the COMPUTED distance value
*/
void Line2D::setLength() { this->length = sqrt(pow((pt1.getX() - pt2.getX()), 2) + pow((pt1.getY() - pt2.getY()), 2)); }

Line2D::Line2D()
{
    // Invoke Point2D's default constructor
    this->pt1 = Point2D();
    this->pt2 = Point2D();
    this->length = 0.0;
}

Line2D::Line2D(Point2D pt1, Point2D pt2) : pt1(pt1), pt2(pt2) { setLength(); }

Point2D Line2D::getPt1() const { return this->pt1; }
Point2D Line2D::getPt2() const { return this->pt2; }
// Return the value of attribute length
double Line2D::getScalarValue() const { return this->length; }

void Line2D::setPt1(Point2D pt1) { this->pt1 = pt1; };
void Line2D::setPt2(Point2D pt2) { this->pt2 = pt2; };

// Operator Overloading
bool Line2D::operator<(const Line2D &rhs) const { return ((this->pt1 < rhs.pt1) || (this->pt2 < rhs.pt2)); }
bool Line2D::operator==(const Line2D &rhs) const { return ((this->pt1 == rhs.pt1) && (this->pt2 == rhs.pt2)); }

// Friend Function
ostream &operator<<(ostream &out, const Line2D &line2D)
{
    out << Formatter::format2DCoordinates(line2D.getPt1().getX(), line2D.getPt1().getY());
    out << Formatter::addSpacing(3);
    out << Formatter::format2DCoordinates(line2D.getPt2().getX(), line2D.getPt2().getY());
    out << Formatter::addSpacing(3);
    out << Formatter::formatDistance(line2D.getScalarValue());
    return out;
}