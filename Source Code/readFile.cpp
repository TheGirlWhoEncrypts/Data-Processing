#include "readFile.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void ReadFile::readAndProcessFile(const vector<string> &VALID_CLASSNAMES, set<Point2D> &point2Ds, set<Line2D> &line2Ds, set<Point3D> &point3Ds, set<Line3D> &line3Ds)
{
    emptySets(point2Ds, line2Ds, point3Ds, line3Ds);
    string validatedFilename = validateFilename();
    storeFileInformation(VALID_CLASSNAMES, validatedFilename, point2Ds, line2Ds, point3Ds, line3Ds);
}

void ReadFile::emptySets(set<Point2D> &point2Ds, set<Line2D> &line2Ds, set<Point3D> &point3Ds, set<Line3D> &line3Ds)
{
    point2Ds.clear();
    line2Ds.clear();
    point3Ds.clear();
    line3Ds.clear();
}

string ReadFile::validateFilename()
{
    string filename;
    bool isFileOpen = false;
    do
    {
        string userInput;
        cout << "Please enter filename : ";
        cin >> userInput;

        fstream inputFile(userInput.c_str(), fstream::in);

        if (!inputFile)
        {
            cerr << "Error opening : " << userInput << "\n"
                 << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
        }
        else
        {
            filename = userInput;
            isFileOpen = true;
        }
        inputFile.close();

    } while (!isFileOpen);

    return filename;
}

void ReadFile::storeFileInformation(const vector<string> &VALID_CLASSNAMES, const string filename, set<Point2D> &point2Ds, set<Line2D> &line2Ds, set<Point3D> &point3Ds, set<Line3D> &line3Ds)
{
    fstream inputFile(filename.c_str(), fstream::in);
    string readLine;
    int i = 0;
    while (getline(inputFile, readLine))
    {
        vector<string> data = tokenizeString(readLine, ", ");

        string classname = data.at(0);
        vector<int> coordinates;

        getCoordinates(data, coordinates);

        // Point2D
        if (classname.compare(VALID_CLASSNAMES.at(0)) == 0)
        {
            Point2D point2D(coordinates.at(0), coordinates.at(1));
            point2Ds.insert(point2D);
        }
        // Point3D
        else if (classname.compare(VALID_CLASSNAMES.at(1)) == 0)
        {
            Point3D point3D(coordinates.at(0), coordinates.at(1), coordinates.at(2));
            point3Ds.insert(point3D);
        }
        // Line2D
        else if (classname.compare(VALID_CLASSNAMES.at(2)) == 0)
        {
            Point2D point2D_1(coordinates.at(0), coordinates.at(1));
            Point2D point2D_2(coordinates.at(2), coordinates.at(3));
            Line2D line2D(point2D_1, point2D_2);
            line2Ds.insert(line2D);
        }
        // Line3D
        else
        {
            Point3D point3D_1(coordinates.at(0), coordinates.at(1), coordinates.at(2));
            Point3D point3D_2(coordinates.at(3), coordinates.at(4), coordinates.at(5));
            Line3D line3D(point3D_1, point3D_2);
            line3Ds.insert(line3D);
        }

        ++i;
    }
    printSuccessMessage(i);
    inputFile.close();
}

void ReadFile::getCoordinates(vector<string> &data, vector<int> &coordinates)
{
    for (int i = 1; i < data.size(); i++)
    {
        removeBrackets(data.at(i));
        coordinates.push_back(stoi(data.at(i)));
    }
}

void ReadFile::removeBrackets(string &data)
{
    size_t foundOpenBracket = data.find("[");
    size_t foundCloseBracket = data.find("]");

    if (foundOpenBracket != string::npos)
    {
        data = data.substr(1);
    }
    if (foundCloseBracket != string::npos)
    {
        data = data.substr(0, (data.length() - 1));
    }
}

void ReadFile::printSuccessMessage(const int &noOfRecordsRead)
{
    cout << "\n"
         << noOfRecordsRead << " records read in successfully!\n\nGoing back to main menu ...\n"
         << endl;
}

vector<string> ReadFile::tokenizeString(string str, string delimiter)
{
    size_t pos = 0;
    string token;
    vector<string> result;

    while ((pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0, pos);
        result.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    result.push_back(str);
    return result;
}
