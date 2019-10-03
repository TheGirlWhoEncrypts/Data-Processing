#include <cmath>

template <typename T>
double scalar_difference(T pt1, T pt2) { return abs(pt1.getScalarValue() - pt2.getScalarValue()); }

template <typename T>
bool equals(T pt1, T pt2) { return (pt1 == pt2); }