#ifndef SPECIFICATION_H
#define SPECIFICATION_H

#include "main.h"
#include "arrange.h"
#include "formatter.h"

#include <iostream>
#include <string>
#include <vector>

namespace Specification
{
// Set Specification
void setSpecification(const int &choiceNumber, const std::vector<std::string> &vector, const std::string &specificationType, const std::string &str, const char &min, const char &max, const bool &isSortingOrder, const bool &isLength);
void printSubMenu(const std::vector<std::string> &vector, const std::string &str, const bool &isSortingOrder, const bool &isLength);
char getUserCriteria(const char &min, const char &max);
bool charValidation(std::string userInput, const char &min, const char &max);
void printSuccessMessage(const std::string &specificationType);
void processUserCriteria(const int &choiceNumber, const char &userCriteria, const std::vector<std::string> &vector, bool &isQuit);

// Get Specification
std::string getResult(CurrentStatus &currentStatus, int &noOfRecordsOutputted);

// Execute Specification
void emptyVectors();
void transferFromSetToVector();

void getAllSpecificationIndex(CurrentStatus &currentStatus, int &selected_filterCriteria, int &selected_SortingCriteria, int &selected_SortingOrder);
void getFoundElementIndex(int &elementIndex, std::vector<std::string> &vectorName, const std::vector<std::string>::iterator &itr);

void applySpecifications(const int &selected_filterCriteria, const int &selected_SortingCriteria, const int &selected_SortingOrder);
void sortPoint2D(const int &selected_SortingCriteria, const int &selected_SortingOrder);
void sortPoint3D(const int &selected_SortingCriteria, const int &selected_SortingOrder);
void sortLine2D(const int &selected_SortingCriteria, const int &selected_SortingOrder);
void sortLine3D(const int &selected_SortingCriteria, const int &selected_SortingOrder);

template <typename T>
std::string classVector_toString(CurrentStatus &currentStatus, const std::vector<T> &vectorName, int &noOfRecordsOutputted);
std::string class_toString(CurrentStatus &currentStatus, const int &selected_filterCriteria, int &noOfRecordsOutputted);
}

#endif