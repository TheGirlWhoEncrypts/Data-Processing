#include "arrange.h"

// Comparator Function
// X            // Point 2D, 3D, Line 2D
bool Arrange::sortByX_ascending(const Point2D &lhs, const Point2D &rhs) { return lhs.getX() < rhs.getX(); }
bool Arrange::sortByX_descending(const Point2D &lhs, const Point2D &rhs) { return lhs.getX() > rhs.getX(); }

// Y            // Point 2D, 3D, Line 2D
bool Arrange::sortByY_ascending(const Point2D &lhs, const Point2D &rhs) { return lhs.getY() < rhs.getY(); }
bool Arrange::sortByY_descending(const Point2D &lhs, const Point2D &rhs) { return lhs.getY() > rhs.getY(); }

// Z            // Point 3D
bool Arrange::sortByZ_ascending(const Point3D &lhs, const Point3D &rhs) { return lhs.getZ() < rhs.getZ(); }
bool Arrange::sortByZ_descending(const Point3D &lhs, const Point3D &rhs) { return lhs.getZ() > rhs.getZ(); }

// Distance     // Point 2D, 3D
bool Arrange::sortByDistance_ascending(const Point2D &lhs, const Point2D &rhs) { return lhs.getScalarValue() < rhs.getScalarValue(); }
bool Arrange::sortByDistance_descending(const Point2D &lhs, const Point2D &rhs) { return lhs.getScalarValue() > rhs.getScalarValue(); }

// PT 1's XY    // Line 2D
bool Arrange::line2D_sortByXY_Pt1_ascending(const Line2D &lhs, const Line2D &rhs) { return ((lhs.getPt1().getX() == rhs.getPt1().getX()) ? sortByY_ascending(lhs.getPt1(), rhs.getPt1()) : sortByX_ascending(lhs.getPt1(), rhs.getPt1())); }
bool Arrange::line2D_sortByXY_Pt1_descending(const Line2D &lhs, const Line2D &rhs) { return ((lhs.getPt1().getX() == rhs.getPt1().getX()) ? sortByY_descending(lhs.getPt1(), rhs.getPt1()) : sortByX_descending(lhs.getPt1(), rhs.getPt1())); }

// PT 2's XY    // Line 2D
bool Arrange::line2D_sortByXY_Pt2_ascending(const Line2D &lhs, const Line2D &rhs) { return ((lhs.getPt2().getX() == rhs.getPt2().getX()) ? sortByY_ascending(lhs.getPt2(), rhs.getPt2()) : sortByX_ascending(lhs.getPt2(), rhs.getPt2())); }
bool Arrange::line2D_sortByXY_Pt2_descending(const Line2D &lhs, const Line2D &rhs) { return ((lhs.getPt2().getX() == rhs.getPt2().getX()) ? sortByY_descending(lhs.getPt2(), rhs.getPt2()) : sortByX_descending(lhs.getPt2(), rhs.getPt2())); }

// Distance     // Line 2D, 3D
bool Arrange::line_sortByDistance_ascending(const Line2D &lhs, const Line2D &rhs) { return lhs.getScalarValue() < rhs.getScalarValue(); }
bool Arrange::line_sortByDistance_descending(const Line2D &lhs, const Line2D &rhs) { return lhs.getScalarValue() > rhs.getScalarValue(); }

// PT 1's XY    // Line 3D
bool Arrange::line3D_sortByXY_Pt1_ascending(const Line3D &lhs, const Line3D &rhs) { return ((lhs.getPt1().getX() == rhs.getPt1().getX()) ? sortByY_ascending(lhs.getPt1(), rhs.getPt1()) : sortByX_ascending(lhs.getPt1(), rhs.getPt1())); }
bool Arrange::line3D_sortByXY_Pt1_descending(const Line3D &lhs, const Line3D &rhs) { return ((lhs.getPt1().getX() == rhs.getPt1().getX()) ? sortByY_descending(lhs.getPt1(), rhs.getPt1()) : sortByX_descending(lhs.getPt1(), rhs.getPt1())); }

// PT 2's XY    // Line 3D
bool Arrange::line3D_sortByXY_Pt2_ascending(const Line3D &lhs, const Line3D &rhs) { return ((lhs.getPt2().getX() == rhs.getPt2().getX()) ? sortByY_ascending(lhs.getPt2(), rhs.getPt2()) : sortByX_ascending(lhs.getPt2(), rhs.getPt2())); }
bool Arrange::line3D_sortByXY_Pt2_descending(const Line3D &lhs, const Line3D &rhs) { return ((lhs.getPt2().getX() == rhs.getPt2().getX()) ? sortByY_descending(lhs.getPt2(), rhs.getPt2()) : sortByX_descending(lhs.getPt2(), rhs.getPt2())); }
