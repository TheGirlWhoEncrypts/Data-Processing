#ifndef MAIN_H
#define MAIN_H

#include "readFile.h"
#include "CurrentStatus.h"
#include "formatter.h"
#include "specification.h"
#include "writeFile.h"

#include "Point2D.h"
#include "Point3D.h"
#include "Line2D.h"
#include "Line3D.h"

#include <iostream>
#include <vector>
#include <iomanip>
#include <set>
#include <string>
#include <sstream>
#include <fstream>

/* ------------------------------------ Global Variables ------------------------------------ */
extern std::vector<std::string> VALID_CLASSNAMES;
extern std::vector<std::string> VALID_SORTING_CRITERIA_POINT_2D;
extern std::vector<std::string> VALID_SORTING_CRITERIA_POINT_3D;
extern std::vector<std::string> VALID_SORTING_CRITERIA_LINE;
extern std::vector<std::string> VALID_SORTING_ORDER;

// STL::sets for each class
extern std::set<Point2D> point2Ds;
extern std::set<Line2D> line2Ds;
extern std::set<Point3D> point3Ds;
extern std::set<Line3D> line3Ds;

// STL::vector for each class
extern std::vector<Point2D> point2Ds_vector;
extern std::vector<Line2D> line2Ds_vector;
extern std::vector<Point3D> point3Ds_vector;
extern std::vector<Line3D> line3Ds_vector;

// Main
void executeProgram();
void printMainMenu();
void printStringVector(const std::vector<std::string> &vector, int width, bool isStatus);
std::string displayStatus(const std::string status);
void setWidth(std::string str, const int &width);

int getUserChoiceInput();
bool integerValidation(int userInput, int min, int max);
void clearInputBuffer();
void printErrorMessage();

void printOption(int userChoiceInput, const std::string currentStatus);

void processUserChoiceInput(int userChoiceInput, bool &isQuit);
void executeUserChoiceInput(const int choiceNumber);

// Specify filtering criteria
void specifyFilteringCriteria(const int &choiceNumber);
void setFilteringCriteria(const char &userCriteria);

// Specify sorting criteria
void specifySortingCriteria(const int &choiceNumber);
void setSortingCriteria(const char &userCriteria, const std::vector<std::string> &vector);

// Specify sorting order
void specifySortingOrder(const int &choiceNumber);
void setSortingOrder(const char &userCriteria, const std::vector<std::string> &vector);

// Specify MINIMUM length OR distance
void specifyMinDistance();
double getValidatedInput(const std::string &str);

// Specify MAXIMUM length OR distance
void specifyMaxDistance();

// View data
void viewData();
void printSpecifications();
void pressAnyKeyToContinue();

#endif