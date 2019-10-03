#ifndef FORMATTER_H
#define FORMATTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <vector>

namespace Formatter
{
// For individual instance
std::string format2DCoordinates(int x, int y);
std::string format3DCoordinates(int x, int y, int z);

template <typename T>
std::string alignment(T value, const int width);

std::string addSpacing(const int space);

std::string formatDistance(double value, bool isNewLine = true);
double getThreeSigFig(double value);

// For individual class's Header
std::string addHeader(const std::vector<std::string> &headers, const std::string distanceHeader, const bool is2D, bool isPointClass);
std::string getPointClass(const std::vector<std::string> &headers);
std::string getLineClass(const std::vector<std::string> &headers);
std::string getLineHeader(const int index, const std::string axis);
std::string addSeparator(const int num);
}

#endif