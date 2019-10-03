#ifndef WRITE_FILE_H
#define WRITE_FILE_H

#include "CurrentStatus.h"
#include "specification.h"
#include "main.h"

#include <iostream>
#include <fstream>
namespace WriteFile
{
void writeFile(CurrentStatus &currentStatus, int &noOfRecordsOutputted);
void printSuccessMessage(const int &noOfRecordsOutputted);
}
#endif