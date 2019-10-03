#include "CurrentStatus.h"

#include <string>
#include <iostream>

using namespace std;

// Default
CurrentStatus::CurrentStatus()
{
    this->filteringCriteria = "Point2D";
    this->sortingCriteria = "x-ordinate";
    this->sortingOrder = "ASC";

    this->minDistance = -1.0;
    this->maxDistance = -1.0;

    this->isMinDistanceSet = false;
    this->isMaxDistanceSet = false;
}

// Getters
string CurrentStatus::getFilteringCriteria() const { return filteringCriteria; }
string CurrentStatus::getSortingCriteria() const { return sortingCriteria; }
string CurrentStatus::getSortingOrder() const { return sortingOrder; }
vector<string> CurrentStatus::getAllStatus() const
{
    vector<string> status{filteringCriteria, sortingCriteria, sortingOrder};
    status.push_back((isMinDistanceSet) ? Formatter::formatDistance(minDistance, false) : "NIL");
    status.push_back((isMaxDistanceSet) ? Formatter::formatDistance(maxDistance, false) : "NIL");
    return status;
}

double CurrentStatus::getMinDistance() const { return minDistance; }
double CurrentStatus::getMaxDistance() const { return maxDistance; }
bool CurrentStatus::getIsMinDistanceSet() const { return isMinDistanceSet; }
bool CurrentStatus::getIsMaxDistanceSet() const { return isMaxDistanceSet; }

// Setters
void CurrentStatus::setFilteringCriteria(string filteringCriteria) { this->filteringCriteria = filteringCriteria; };
void CurrentStatus::setSortingCriteria(string sortingCriteria) { this->sortingCriteria = sortingCriteria; };
void CurrentStatus::setSortingOrder(string sortingOrder) { this->sortingOrder = sortingOrder; };

void CurrentStatus::setMinDistance(double minDistance) { this->minDistance = minDistance; }
void CurrentStatus::setMaxDistance(double maxDistance) { this->maxDistance = maxDistance; }
void CurrentStatus::setIsMinDistanceSet(bool isMinDistanceSet) { this->isMinDistanceSet = isMinDistanceSet; }
void CurrentStatus::setIsMaxDistanceSet(bool isMaxDistanceSet) { this->isMaxDistanceSet = isMaxDistanceSet; }