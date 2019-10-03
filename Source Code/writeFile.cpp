#include "writeFile.h"
using namespace std;

void WriteFile::writeFile(CurrentStatus &currentStatus, int &noOfRecordsOutputted)
{
    string filename;
    bool isFileOpen = false;
    bool isDoneWriting = false;
    do
    {
        cout << "Please enter filename : ";
        cin >> filename;

        // Write to File
        fstream outputFile(filename.c_str(), fstream::out);

        if (!outputFile)
        {
            clearInputBuffer();
            cerr << "Error opening : " << filename << "\n"
                 << endl;
        }
        else
        {
            isFileOpen = true;
            outputFile << Specification::getResult(currentStatus, noOfRecordsOutputted);
            isDoneWriting = true; // Need to be in the function NOT HERE
        }
        outputFile.close();
    } while (!isFileOpen && !isDoneWriting);
    printSuccessMessage(noOfRecordsOutputted);
}

void WriteFile::printSuccessMessage(const int &noOfRecordsOutputted)
{
    cout << "\n"
         << noOfRecordsOutputted << " records output successfully!\n\nGoing back to main menu ...\n"
         << endl;
}