#ifndef POINT_3D_H
#define POINT_3D_H

#include "Point2D.h"

class Point3D : public Point2D
{
  friend std::ostream &operator<<(std::ostream &out, const Point3D &point3D); // out << point3D
protected:
  int z;
  /* 
    - Computes the distance of the point to the orgin (0, 0, 0) + 
    - Initialize the attribute distFrOrgin with this COMPUTED distance value
    */
  void setDistFrOrigin();

public:
  Point3D(int x = 0, int y = 0, int z = 0);

  int getZ() const;
  void setZ(int z);

  // Operator Overloading
  bool operator<(const Point3D &rhs) const;
  bool operator==(const Point3D &rhs) const;
};
#endif