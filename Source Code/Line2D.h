#ifndef LINE_2D_H
#define LINE_2D_H

#include "Point2D.h"
#include "formatter.h"

class Line2D
{
  friend std::ostream &operator<<(std::ostream &out, const Line2D &line2D); // out << line2D
private:
  Point2D pt1, pt2;

protected:
  double length;
  /* 
    - Computes the distance between its own Point2D attributes pt1 and pt2
    - Initializes the attribute length with the COMPUTED distance value
    */
  void setLength();

public:
  Line2D();
  Line2D(Point2D pt1, Point2D pt2);

  Point2D getPt1() const;
  Point2D getPt2() const;
  // Return the value of attribute length
  double getScalarValue() const;

  void setPt1(Point2D pt1);
  void setPt2(Point2D pt2);

  // Operator Overloading
  bool operator<(const Line2D &rhs) const;
  bool operator==(const Line2D &rhs) const;
};

#endif