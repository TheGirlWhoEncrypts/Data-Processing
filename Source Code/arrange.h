#ifndef ARRANGE_H
#define ARRANGE_H

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

namespace Arrange
{
// Comparator Function
// X            // Point 2D, 3D, Line 2D
bool sortByX_ascending(const Point2D &lhs, const Point2D &rhs);
bool sortByX_descending(const Point2D &lhs, const Point2D &rhs);

// Y            // Point 2D, 3D, Line 2D
bool sortByY_ascending(const Point2D &lhs, const Point2D &rhs);
bool sortByY_descending(const Point2D &lhs, const Point2D &rhs);

// Z            // Point 3D
bool sortByZ_ascending(const Point3D &lhs, const Point3D &rhs);
bool sortByZ_descending(const Point3D &lhs, const Point3D &rhs);

// Distance     // Point 2D, 3D
bool sortByDistance_ascending(const Point2D &lhs, const Point2D &rhs);
bool sortByDistance_descending(const Point2D &lhs, const Point2D &rhs);

// PT 1's XY    // Line 2D
bool line2D_sortByXY_Pt1_ascending(const Line2D &lhs, const Line2D &rhs);
bool line2D_sortByXY_Pt1_descending(const Line2D &lhs, const Line2D &rhs);

// PT 2's XY    // Line 2D
bool line2D_sortByXY_Pt2_ascending(const Line2D &lhs, const Line2D &rhs);
bool line2D_sortByXY_Pt2_descending(const Line2D &lhs, const Line2D &rhs);

// Distance     // Line 2D, 3D
bool line_sortByDistance_ascending(const Line2D &lhs, const Line2D &rhs);
bool line_sortByDistance_descending(const Line2D &lhs, const Line2D &rhs);

// PT 1's XY    // Line 3D
bool line3D_sortByXY_Pt1_ascending(const Line3D &lhs, const Line3D &rhs);
bool line3D_sortByXY_Pt1_descending(const Line3D &lhs, const Line3D &rhs);

// PT 2's XY    // Line 3D
bool line3D_sortByXY_Pt2_ascending(const Line3D &lhs, const Line3D &rhs);
bool line3D_sortByXY_Pt2_descending(const Line3D &lhs, const Line3D &rhs);
}
#endif