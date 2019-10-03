#ifndef READ_FILE_H
#define READ_FILE_H

#include "Point2D.h"
#include "Line2D.h"
#include "Point3D.h"
#include "Line3D.h"

#include <string>
#include <vector>
#include <set>

namespace ReadFile
{
void readAndProcessFile(const std::vector<std::string> &VALID_CLASSNAMES, std::set<Point2D> &point2Ds, std::set<Line2D> &line2Ds, std::set<Point3D> &point3Ds, std::set<Line3D> &line3Ds);
void emptySets(std::set<Point2D> &point2Ds, std::set<Line2D> &line2Ds, std::set<Point3D> &point3Ds, std::set<Line3D> &line3Ds);

std::string validateFilename();

void storeFileInformation(const std::vector<std::string> &VALID_CLASSNAMES, const std::string filename, std::set<Point2D> &point2Ds, std::set<Line2D> &line2Ds, std::set<Point3D> &point3Ds, std::set<Line3D> &line3Ds);
void getCoordinates(std::vector<std::string> &data, std::vector<int> &coordinates);
void removeBrackets(std::string &data);
void printSuccessMessage(const int &noOfRecordsRead);
std::vector<std::string> tokenizeString(std::string str, std::string delimiter);
}
#endif