#include "formatter.h"

using namespace std;

// For individual instance
string Formatter::format2DCoordinates(int x, int y)
{
    ostringstream os;
    os << "[" << alignment(x, 4) << ", " << alignment(y, 4) << "]";
    return os.str();
}

string Formatter::format3DCoordinates(int x, int y, int z)
{
    ostringstream os;
    os << "[" << alignment(x, 4) << ", " << alignment(y, 4) << ", " << alignment(z, 4) << "]";
    return os.str();
}

template <typename T>
string Formatter::alignment(T value, const int width)
{
    ostringstream os;
    os << right << setw(width) << value;
    return os.str();
}

string Formatter::addSpacing(const int space)
{
    string spacing(space, ' ');
    return spacing;
}

string Formatter::formatDistance(double value, bool isNewLine)
{
    ostringstream os;
    os << fixed << setprecision(3) << getThreeSigFig(value);
    os << ((isNewLine) ? "\n" : "");
    return os.str();
}

double Formatter::getThreeSigFig(double value) { return (round(value * 1000.0) / 1000.0); }

// For individual class's Header
string Formatter::addHeader(const vector<string> &headers, const string distanceHeader, const bool is2D, bool isPointClass)
{
    ostringstream os;
    os << ((isPointClass) ? getPointClass(headers) : getLineClass(headers));
    os << addSpacing(4);
    os << distanceHeader << endl;
    os << ((isPointClass) ? ((is2D) ? addSeparator(31) : addSeparator(37)) : ((is2D) ? addSeparator(37) : addSeparator(49))) << endl;
    return os.str();
}

string Formatter::getPointClass(const vector<string> &headers)
{
    ostringstream os;
    os << addSpacing(1);
    for (int i = 0; i < headers.size(); i++)
    {
        os << alignment(headers.at(i), 4);
        if (i <= headers.size() - 2)
        {
            os << addSpacing(2);
        }
    }
    return os.str();
}

string Formatter::getLineClass(const vector<string> &headers)
{
    ostringstream os;
    vector<string> modifiedHeaders;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < headers.size(); j++)
        {
            modifiedHeaders.push_back(getLineHeader(i, headers.at(j)));
        }
        os << getPointClass(modifiedHeaders);
        modifiedHeaders.clear();
        if (i == 0)
        {
            os << addSpacing(4);
        }
    }
    return os.str();
}

string Formatter::getLineHeader(const int index, const string axis)
{
    ostringstream os;
    os << "P" << (index + 1) << "-" << axis;
    return os.str();
}

string Formatter::addSeparator(const int num)
{
    string dash(num, '-');
    return dash;
}