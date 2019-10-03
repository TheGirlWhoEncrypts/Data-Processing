#ifndef CURRENT_STATUS_H
#define CURRENT_STATUS_H

#include <string>
#include <vector>
#include "formatter.h"

class CurrentStatus
{
private:
  std::string filteringCriteria, sortingCriteria, sortingOrder;
  double minDistance, maxDistance;
  bool isMinDistanceSet, isMaxDistanceSet;

public:
  // Default
  CurrentStatus();

  // Getters
  std::string getFilteringCriteria() const;
  std::string getSortingCriteria() const;
  std::string getSortingOrder() const;
  std::vector<std::string> getAllStatus() const;

  double getMinDistance() const;
  double getMaxDistance() const;
  bool getIsMinDistanceSet() const;
  bool getIsMaxDistanceSet() const;

  // Setters
  void setFilteringCriteria(std::string filteringCriteria);
  void setSortingCriteria(std::string sortingCriteria);
  void setSortingOrder(std::string sortingOrder);

  void setMinDistance(double minDistance);
  void setMaxDistance(double maxDistance);
  void setIsMinDistanceSet(bool isMinDistanceSet);
  void setIsMaxDistanceSet(bool isMaxDistanceSet);
};

#endif