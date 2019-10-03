#include "specification.h"

using namespace std;

// Set Specification
void Specification::setSpecification(const int &choiceNumber, const vector<string> &vector, const string &specificationType, const string &str, const char &min, const char &max, const bool &isSortingOrder, const bool &isLength)
{
    bool isQuit = false;
    do
    {
        printSubMenu(vector, str, isSortingOrder, isLength);
        char userCriteria = getUserCriteria(min, max);
        // Print Success Message
        if (userCriteria != 'q')
        {
            printSuccessMessage(specificationType);
        }
        processUserCriteria(choiceNumber, userCriteria, vector, isQuit);
        isQuit = true; // To quit once user had enter valid input
    } while (!isQuit);
}

void Specification::printSubMenu(const vector<string> &vector, const string &str, const bool &isSortingOrder, const bool &isLength)
{
    for (int i = 0; i < vector.size(); i++)
    {
        cout << "\t" << char(97 + i) << ")\t" << vector.at(i);
        // For printing ASC and DESC in sorting order
        cout << ((isSortingOrder) ? ((i == 0) ? " (A" : " (De") : "");
        // For class LINE's printing "Length"
        cout << ((isLength && i == vector.size() - 1) ? " value" : str) << endl;
    }
}

char Specification::getUserCriteria(const char &min, const char &max)
{
    char validatedInput;
    string userInput;
    bool isChar = false;
    do
    {
        cout << "\n\tPlease enter your criteria (" << min << " - " << max << "). 'q' to go back to main menu : ";
        cin >> userInput;
        isChar = charValidation(userInput, min, max);
    } while (!isChar);

    validatedInput = userInput.at(0);
    return validatedInput;
}

bool Specification::charValidation(string userInput, const char &min, const char &max)
{
    bool isChar = false;

    char userInput_char = userInput.at(0);
    if (!((userInput_char >= min && userInput_char <= max) || (userInput_char == 'q')) || !isalpha(userInput_char) || userInput.length() != 1)
    {
        clearInputBuffer();
        cout << "\t";
        printErrorMessage();
    }
    else
    {
        isChar = true;
    }
    return isChar;
}

void Specification::printSuccessMessage(const string &specificationType)
{
    cout << "\t" << specificationType << " successfully set to ";
}

void Specification::processUserCriteria(const int &choiceNumber, const char &userCriteria, const vector<string> &vector, bool &isQuit)
{
    if (userCriteria == 'q')
    {
        isQuit = true;
    }
    else if (choiceNumber == 2)
    {
        setFilteringCriteria(userCriteria);
    }
    else if (choiceNumber == 3)
    {
        setSortingCriteria(userCriteria, vector);
    }
    else
    {
        setSortingOrder(userCriteria, vector);
    }
}

// Get Specification
string Specification::getResult(CurrentStatus &currentStatus, int &noOfRecordsOutputted)
{
    emptyVectors();
    transferFromSetToVector();

    int selected_filterCriteria, selected_SortingCriteria, selected_SortingOrder;
    getAllSpecificationIndex(currentStatus, selected_filterCriteria, selected_SortingCriteria, selected_SortingOrder);
    applySpecifications(selected_filterCriteria, selected_SortingCriteria, selected_SortingOrder);

    return class_toString(currentStatus, selected_filterCriteria, noOfRecordsOutputted);
}

// Execute Specification
void Specification::emptyVectors()
{
    point2Ds_vector.clear();
    line2Ds_vector.clear();
    point3Ds_vector.clear();
    line3Ds_vector.clear();
}

void Specification::transferFromSetToVector()
{
    point2Ds_vector.assign(point2Ds.begin(), point2Ds.end());
    line2Ds_vector.assign(line2Ds.begin(), line2Ds.end());
    point3Ds_vector.assign(point3Ds.begin(), point3Ds.end());
    line3Ds_vector.assign(line3Ds.begin(), line3Ds.end());
}

void Specification::getAllSpecificationIndex(CurrentStatus &currentStatus, int &selected_filterCriteria, int &selected_SortingCriteria, int &selected_SortingOrder)
{
    // Find Selected Class
    vector<string>::iterator itr = find(VALID_CLASSNAMES.begin(), VALID_CLASSNAMES.end(), currentStatus.getFilteringCriteria());
    getFoundElementIndex(selected_filterCriteria, VALID_CLASSNAMES, itr);

    // Find Selected Sorting Criteria
    if (selected_filterCriteria == 0)
    {
        itr = find(VALID_SORTING_CRITERIA_POINT_2D.begin(), VALID_SORTING_CRITERIA_POINT_2D.end(), currentStatus.getSortingCriteria());
        getFoundElementIndex(selected_SortingCriteria, VALID_SORTING_CRITERIA_POINT_2D, itr);
    }
    else if (selected_filterCriteria == 1)
    {
        itr = find(VALID_SORTING_CRITERIA_POINT_3D.begin(), VALID_SORTING_CRITERIA_POINT_3D.end(), currentStatus.getSortingCriteria());
        getFoundElementIndex(selected_SortingCriteria, VALID_SORTING_CRITERIA_POINT_3D, itr);
    }
    else
    {
        itr = find(VALID_SORTING_CRITERIA_LINE.begin(), VALID_SORTING_CRITERIA_LINE.end(), currentStatus.getSortingCriteria());
        getFoundElementIndex(selected_SortingCriteria, VALID_SORTING_CRITERIA_LINE, itr);
    }

    // Find Selected Sorting Order
    itr = find(VALID_SORTING_ORDER.begin(), VALID_SORTING_ORDER.end(), currentStatus.getSortingOrder());
    getFoundElementIndex(selected_SortingOrder, VALID_SORTING_ORDER, itr);
}

void Specification::getFoundElementIndex(int &elementIndex, vector<string> &vectorName, const vector<string>::iterator &itr)
{
    if (itr != vectorName.end())
    {
        elementIndex = distance(vectorName.begin(), itr);
    }
}

void Specification::applySpecifications(const int &selected_filterCriteria, const int &selected_SortingCriteria, const int &selected_SortingOrder)
{
    switch (selected_filterCriteria)
    {
    case 0:
        // Point2D
        sortPoint2D(selected_SortingCriteria, selected_SortingOrder);
        break;
    case 1:
        // Point3D
        sortPoint3D(selected_SortingCriteria, selected_SortingOrder);
        break;
    case 2:
        // Line2D
        sortLine2D(selected_SortingCriteria, selected_SortingOrder);
        break;
    case 3:
        // Line3D
        sortLine3D(selected_SortingCriteria, selected_SortingOrder);
        break;
    }
}

void Specification::sortPoint2D(const int &selected_SortingCriteria, const int &selected_SortingOrder)
{
    switch (selected_SortingCriteria)
    {
    case 0:
        // Sort By X
        (selected_SortingOrder == 0) ? sort(point2Ds_vector.begin(), point2Ds_vector.end(), Arrange::sortByX_ascending) : sort(point2Ds_vector.begin(), point2Ds_vector.end(), Arrange::sortByX_descending);
        break;
    case 1:
        // Sort By Y
        (selected_SortingOrder == 0) ? sort(point2Ds_vector.begin(), point2Ds_vector.end(), Arrange::sortByY_ascending) : sort(point2Ds_vector.begin(), point2Ds_vector.end(), Arrange::sortByY_descending);
        break;
    case 2:
        // Sort By Distance
        (selected_SortingOrder == 0) ? sort(point2Ds_vector.begin(), point2Ds_vector.end(), Arrange::sortByDistance_ascending) : sort(point2Ds_vector.begin(), point2Ds_vector.end(), Arrange::sortByDistance_descending);
        break;
    }
}

void Specification::sortPoint3D(const int &selected_SortingCriteria, const int &selected_SortingOrder)
{
    switch (selected_SortingCriteria)
    {
    case 0:
        // Sort By X
        (selected_SortingOrder == 0) ? sort(point3Ds_vector.begin(), point3Ds_vector.end(), Arrange::sortByX_ascending) : sort(point3Ds_vector.begin(), point3Ds_vector.end(), Arrange::sortByX_descending);
        break;
    case 1:
        // Sort By Y
        (selected_SortingOrder == 0) ? sort(point3Ds_vector.begin(), point3Ds_vector.end(), Arrange::sortByY_ascending) : sort(point3Ds_vector.begin(), point3Ds_vector.end(), Arrange::sortByY_descending);
        break;
    case 2:
        // Sort By Z
        (selected_SortingOrder == 0) ? sort(point3Ds_vector.begin(), point3Ds_vector.end(), Arrange::sortByZ_ascending) : sort(point3Ds_vector.begin(), point3Ds_vector.end(), Arrange::sortByZ_descending);
        break;
    case 3:
        // Sort By Distance
        (selected_SortingOrder == 0) ? sort(point3Ds_vector.begin(), point3Ds_vector.end(), Arrange::sortByDistance_ascending) : sort(point3Ds_vector.begin(), point3Ds_vector.end(), Arrange::sortByDistance_descending);
        break;
    }
}

void Specification::sortLine2D(const int &selected_SortingCriteria, const int &selected_SortingOrder)
{
    switch (selected_SortingCriteria)
    {
    case 0:
        // Sort By PT 1's XY
        (selected_SortingOrder == 0) ? sort(line2Ds_vector.begin(), line2Ds_vector.end(), Arrange::line2D_sortByXY_Pt1_ascending) : sort(line2Ds_vector.begin(), line2Ds_vector.end(), Arrange::line2D_sortByXY_Pt1_descending);
        break;
    case 1:
        // Sort By PT 1's XY
        (selected_SortingOrder == 0) ? sort(line2Ds_vector.begin(), line2Ds_vector.end(), Arrange::line2D_sortByXY_Pt2_ascending) : sort(line2Ds_vector.begin(), line2Ds_vector.end(), Arrange::line2D_sortByXY_Pt2_descending);
        break;
    case 2:
        // Sort By Distance
        (selected_SortingOrder == 0) ? sort(line2Ds_vector.begin(), line2Ds_vector.end(), Arrange::line_sortByDistance_ascending) : sort(line2Ds_vector.begin(), line2Ds_vector.end(), Arrange::line_sortByDistance_descending);
        break;
    }
}

void Specification::sortLine3D(const int &selected_SortingCriteria, const int &selected_SortingOrder)
{
    switch (selected_SortingCriteria)
    {
    case 0:
        // Sort By PT 1's XY
        (selected_SortingOrder == 0) ? sort(line3Ds_vector.begin(), line3Ds_vector.end(), Arrange::line3D_sortByXY_Pt1_ascending) : sort(line3Ds_vector.begin(), line3Ds_vector.end(), Arrange::line3D_sortByXY_Pt1_descending);
        break;
    case 1:
        // Sort By PT 1's XY
        (selected_SortingOrder == 0) ? sort(line3Ds_vector.begin(), line3Ds_vector.end(), Arrange::line3D_sortByXY_Pt2_ascending) : sort(line3Ds_vector.begin(), line3Ds_vector.end(), Arrange::line3D_sortByXY_Pt2_descending);
        break;
    case 2:
        // Sort By Distance
        (selected_SortingOrder == 0) ? sort(line3Ds_vector.begin(), line3Ds_vector.end(), Arrange::line_sortByDistance_ascending) : sort(line3Ds_vector.begin(), line3Ds_vector.end(), Arrange::line_sortByDistance_descending);
        break;
    }
}

template <typename T>
string Specification::classVector_toString(CurrentStatus &currentStatus, const std::vector<T> &vectorName, int &noOfRecordsOutputted)
{
    ostringstream os;
    int count = 0;
    for (int i = 0; i < vectorName.size(); i++)
    {
        double distance = vectorName.at(i).getScalarValue();

        // 1. Both min & max distance are set
        if (currentStatus.getIsMinDistanceSet() && currentStatus.getIsMaxDistanceSet())
        {
            if (distance >= currentStatus.getMinDistance() && distance <= currentStatus.getMaxDistance())
            {
                os << vectorName.at(i);
                ++count;
            }
        }
        // 2. Min set only
        else if (currentStatus.getIsMinDistanceSet() && !currentStatus.getIsMaxDistanceSet())
        {
            if (distance >= currentStatus.getMinDistance())
            {
                os << vectorName.at(i);
                ++count;
            }
        }
        // 3. Max set only
        else if (!currentStatus.getIsMinDistanceSet() && currentStatus.getIsMaxDistanceSet())
        {
            if (distance <= currentStatus.getMaxDistance())
            {
                os << vectorName.at(i);
                ++count;
            }
        }
        // 4. Both min & max distance are not set
        else
        {
            os << vectorName.at(i);
            ++count;
        }
    }
    os << endl;
    noOfRecordsOutputted = count;
    return os.str();
}

string Specification::class_toString(CurrentStatus &currentStatus, const int &selected_filterCriteria, int &noOfRecordsOutputted)
{
    const vector<string> XY = {"X", "Y"};
    const vector<string> XYZ = {"X", "Y", "Z"};

    ostringstream os;

    switch (selected_filterCriteria)
    {
        // Point2D
    case 0:
        os << Formatter::addHeader(XY, "Dist. Fr Origin", true, true);
        os << classVector_toString(currentStatus, point2Ds_vector, noOfRecordsOutputted);
        break;
        // Point3D
    case 1:
        os << Formatter::addHeader(XYZ, "Dist. Fr Origin", false, true);
        os << classVector_toString(currentStatus, point3Ds_vector, noOfRecordsOutputted);
        break;
        // Line2D
    case 2:
        os << Formatter::addHeader(XY, "Length", true, false);
        os << classVector_toString(currentStatus, line2Ds_vector, noOfRecordsOutputted);
        break;
        // Line3D
    case 3:
        os << Formatter::addHeader(XYZ, "Length", false, false);
        os << classVector_toString(currentStatus, line3Ds_vector, noOfRecordsOutputted);
        break;
    }
    return os.str();
}
