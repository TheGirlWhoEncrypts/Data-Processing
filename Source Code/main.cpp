// g++ -std=c++11 main.cpp readFile.cpp specification.cpp writeFile.cpp CurrentStatus.cpp arrange.cpp Line3D.cpp Line2D.cpp Point3D.cpp Point2D.cpp formatter.cpp -o main.exe

#include "main.h"

using namespace std;

/* ------------------------------------ Global Variables ------------------------------------ */
const string DIVIDER = "-----------------------------------------------------------\n";
const vector<string> STUDENT_INFORMATION = {"\nStudent ID", ": 123456", "Student Name", ": Jane Doe"};

CurrentStatus currentStatus;
int noOfRecordsOutputted;

const vector<string> OPTIONS = {
    "1)", "Read in data",
    "2)", "Specify filtering criteria",
    "3)", "Specify sorting criteria",
    "4)", "Specify sorting order",
    "5)", "Specify minimum length OR distance",
    "6)", "Specify maximum length OR distance",
    "7)", "View data",
    "8)", "Store data",
    "9)", "Quit"};

vector<string> VALID_CLASSNAMES = {"Point2D", "Point3D", "Line2D", "Line3D"};

vector<string> VALID_SORTING_CRITERIA_POINT_2D = {"x-ordinate", "y-ordinate", "Dist. Fr Origin"};
vector<string> VALID_SORTING_CRITERIA_POINT_3D = {"x-ordinate", "y-ordinate", "z-ordinate", "Dist. Fr Origin"};
vector<string> VALID_SORTING_CRITERIA_LINE = {"Pt. 1", "Pt. 2", "Length"};

vector<string> VALID_SORTING_ORDER = {"ASC", "DSC"};

const string PLEASE_ENTER = "\nPlease enter ";

// STL::sets for each class
set<Point2D> point2Ds;
set<Line2D> line2Ds;
set<Point3D> point3Ds;
set<Line3D> line3Ds;

// STL::vector for each class
vector<Point2D> point2Ds_vector;
vector<Line2D> line2Ds_vector;
vector<Point3D> point3Ds_vector;
vector<Line3D> line3Ds_vector;

using namespace std;
/* ------------------------------------- Main() ----------------------------------------------------- */
int main()
{
    executeProgram();
}

/* ------------------------------------- Function Implementation ----------------------------------------------------- */
void executeProgram()
{
    bool isQuit = false;
    do
    {
        printMainMenu();
        int userChoiceInput = getUserChoiceInput();

        string currentStatusType =
            (userChoiceInput >= 2 && userChoiceInput <= 6) ? displayStatus(currentStatus.getAllStatus().at(userChoiceInput - 2)) : "";

        printOption(userChoiceInput, currentStatusType);
        processUserChoiceInput(userChoiceInput, isQuit);

    } while (!isQuit);
}

void printMainMenu()
{
    printStringVector(STUDENT_INFORMATION, 15, false);
    cout << DIVIDER << "Welcome to Assn3 program!\n"
         << endl;
    printStringVector(OPTIONS, 7, true);
}

void printStringVector(const vector<string> &vector, int width, bool isStatus)
{
    int j = 0;
    for (int i = 0; i < vector.size(); i++)
    {
        if (i % 2 == 0)
        {
            setWidth(vector.at(i), width);
        }
        else
        {
            cout << vector.at(i);
            if (isStatus && (i >= 3 && i <= 11))
            {
                cout << displayStatus(currentStatus.getAllStatus().at(j));
                j++;
            }
            cout << endl;
        }
    }
    j = 0;
}

string displayStatus(const string status)
{
    ostringstream os;
    os << " (current : " << status << ")";
    return os.str();
}

void setWidth(string str, const int &width)
{
    cout << left << setw(width) << str;
}

int getUserChoiceInput()
{
    int validatedInput = -1, userInput;
    bool isInteger = false;
    do
    {
        cout << PLEASE_ENTER << "your choice : ";
        cin >> userInput;
        isInteger = integerValidation(userInput, 1, 9);
    } while (!isInteger);

    validatedInput = userInput;
    return validatedInput;
}

bool integerValidation(int userInput, int min, int max)
{
    bool isInteger = false;

    if (!isdigit(userInput) && !(userInput >= min && userInput <= max))
    {
        clearInputBuffer();
        printErrorMessage();
    }
    else
    {
        isInteger = true;
    }
    return isInteger;
}

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printErrorMessage()
{
    cerr << "ERROR : Invalid Input\n"
         << endl;
}

void printOption(int userChoiceInput, const string currentStatus)
{
    cout << "\n[" << OPTIONS[(userChoiceInput * 2) - 1] << currentStatus << "]\n"
         << endl;
}

void processUserChoiceInput(int userChoiceInput, bool &isQuit)
{
    if (userChoiceInput == 9)
    {
        isQuit = true;
    }
    else
    {
        executeUserChoiceInput(userChoiceInput);
    }
}

void executeUserChoiceInput(const int choiceNumber)
{
    switch (choiceNumber)
    {
    case 1:
        ReadFile::readAndProcessFile(VALID_CLASSNAMES, point2Ds, line2Ds, point3Ds, line3Ds);
        break;
    case 2:
        specifyFilteringCriteria(choiceNumber);
        break;
    case 3:
        specifySortingCriteria(choiceNumber);
        break;
    case 4:
        specifySortingOrder(choiceNumber);
        break;
    case 5:
        specifyMinDistance();
        break;
    case 6:
        specifyMaxDistance();
        break;
    case 7:
        viewData();
        break;
    case 8:
        WriteFile::writeFile(currentStatus, noOfRecordsOutputted);
        break;
    }
}

/* ------------------------------------- Specify filtering criteria  -------------------------------- */
void specifyFilteringCriteria(const int &choiceNumber)
{
    Specification::setSpecification(choiceNumber, VALID_CLASSNAMES, "Filter criteria", " records", 'a', 'd', false, false);
}

void setFilteringCriteria(const char &userCriteria)
{
    currentStatus.setFilteringCriteria(VALID_CLASSNAMES.at(int(userCriteria) - 97));

    (userCriteria == 'a' || userCriteria == 'b')
        ? currentStatus.setSortingCriteria(VALID_SORTING_CRITERIA_POINT_2D.at(0))
        : currentStatus.setSortingCriteria(VALID_SORTING_CRITERIA_LINE.at(0));

    currentStatus.setSortingOrder(VALID_SORTING_ORDER.at(0));

    // Reset Distance to default values
    currentStatus.setMinDistance(-1);
    currentStatus.setIsMinDistanceSet(false);

    currentStatus.setMaxDistance(-1);
    currentStatus.setIsMaxDistanceSet(false);

    // Print
    cout << "'" << currentStatus.getFilteringCriteria() << "'!" << endl;
}

/* ------------------------------------- Specify sorting criteria  ---------------------------------- */
void specifySortingCriteria(const int &choiceNumber)
{
    //   Point2D
    if (currentStatus.getFilteringCriteria() == VALID_CLASSNAMES.at(0))
    {
        Specification::setSpecification(choiceNumber, VALID_SORTING_CRITERIA_POINT_2D, "Sorting criteria", " value", 'a', 'c', false, false);
    }
    // Point3D
    else if (currentStatus.getFilteringCriteria() == VALID_CLASSNAMES.at(1))
    {
        Specification::setSpecification(choiceNumber, VALID_SORTING_CRITERIA_POINT_3D, "Sorting criteria", " value", 'a', 'd', false, false);
    }
    // Line2D or Line3D
    else
    {
        Specification::setSpecification(choiceNumber, VALID_SORTING_CRITERIA_LINE, "Sorting criteria", "'s (x, y) values", 'a', 'c', false, true);
    }
}

void setSortingCriteria(const char &userCriteria, const vector<string> &vector)
{
    currentStatus.setSortingCriteria(vector.at(int(userCriteria) - 97));
    currentStatus.setSortingOrder(VALID_SORTING_ORDER.at(0));
    cout << "'" << currentStatus.getSortingCriteria() << "'!" << endl;
}

/* ------------------------------------- Specify sorting order  ------------------------------------- */
void specifySortingOrder(const int &choiceNumber)
{
    Specification::setSpecification(choiceNumber, VALID_SORTING_ORDER, "Sorting order", "scending order)", 'a', 'b', true, false);
}

void setSortingOrder(const char &userCriteria, const vector<string> &vector)
{
    currentStatus.setSortingOrder(vector.at(int(userCriteria) - 97));
    cout << "'" << currentStatus.getSortingOrder() << "'!" << endl;
}

/* ------------------------------------- Specify MINIMUM length OR distance  ------------------------------------- */
void specifyMinDistance()
{
    currentStatus.setMinDistance(getValidatedInput("minimum"));
    currentStatus.setIsMinDistanceSet(true);
}

double getValidatedInput(const string &str)
{
    bool isDigit = false;
    double validatedMinInput, userInput;
    do
    {
        cout << PLEASE_ENTER << "the " << str << " distance for " << currentStatus.getFilteringCriteria() << " : ";
        cin >> userInput;

        if (!isdigit(userInput) && userInput <= 0)
        {
            clearInputBuffer();
            printErrorMessage();
        }
        else
        {
            isDigit = true;
        }
    } while (!isDigit);
    validatedMinInput = userInput;
    return validatedMinInput;
}

/* ------------------------------------- Specify MAXIMUM length OR distance  ------------------------------------- */
void specifyMaxDistance()
{
    currentStatus.setMaxDistance(getValidatedInput("maximum"));
    currentStatus.setIsMaxDistanceSet(true);
}

/* ------------------------------------- View data  ------------------------------------------------- */
void viewData()
{
    printSpecifications();
    cout << Specification::getResult(currentStatus, noOfRecordsOutputted);
    pressAnyKeyToContinue();
}

void printSpecifications()
{
    vector<string> title = {"  Filtering criteria", "  Sorting criteria", "  Sorting order", "  Minimum Distance", "  Maximum Distance"};
    for (int i = 0; i < title.size(); i++)
    {
        setWidth(title.at(i), 20);
        cout << " : " << currentStatus.getAllStatus().at(i) << endl;
    }
    cout << endl;
}

void pressAnyKeyToContinue()
{
    cout << "\nPress any key to go back to main menu ...";
    cin.get();
    clearInputBuffer();
}
