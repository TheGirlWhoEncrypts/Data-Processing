#ifndef POINT_2D_H
#define POINT_2D_H

#include "formatter.h"

#include <iostream>

class Point2D
{
  friend std::ostream &operator<<(std::ostream &out, const Point2D &point2D); // out << point2D

protected:
  int x, y;
  double distFrOrigin;
  /* 
        - Computes the distance of the point to the orgin (0, 0) + 
        - Initialize the attribute distFrOrgin with this COMPUTED distance value
    */
  void setDistFrOrigin();

public:
  Point2D(int x = 0, int y = 0);

  int getX() const;
  int getY() const;
  // Return the value attribute distFrOrigin
  double getScalarValue() const;

  void setX(int x);
  void setY(int y);

  // Operator Overloading
  bool operator<(const Point2D &rhs) const;
  bool operator==(const Point2D &rhs) const;
};

#endif
