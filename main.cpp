#include <iostream>
#include <fstream>

using namespace std;

string removeSpaces(string str);
string sortString (string str);
bool isAnagram(string str1, string str2);
string makeLower (string str);

int main()
{
    ifstream inFile;
    inFile.open("input.txt");

    ofstream outfile;
    outfile.open("output.txt");

    string a,b, stringOne, stringTwo, sortedStringOne, sortedStringTwo;
    string temp1, temp2;
    while (getline (inFile,a))
    {
        getline (inFile,b);
        stringOne = removeSpaces(a);
        stringTwo = removeSpaces(b);
        stringOne = makeLower(stringOne);
        stringTwo = makeLower(stringTwo);
        sortedStringOne = sortString(stringOne);
        sortedStringTwo = sortString(stringTwo);

        outfile << isAnagram(sortedStringOne, sortedStringTwo) << endl;

    }

    return 0;
}


string removeSpaces(string str)
{
    string myString = "";

    for(int i = 0; i < str.size(); i++)
    {
        if (ispunct(str.at(i)) == false && isspace(str.at(i)) == false)
            myString = myString + str.at(i);
    }

    return myString;
}

string sortString (string str)
{
    char temp;

    for(int i = 0; i < str.size() - 1; i++)
    {
        for(int j = i + 1; j < str.size(); j++)
        {
            if (int (str.at(i)) > int (str.at(j)))
            {
                temp = str.at(i);
                str.at(i) = str.at(j);
                str.at(j) = temp;
            }
        }
    }

    return str;
}

string makeLower (string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        str.at(i) = tolower(str.at(i));
    }

    return str;
}

bool isAnagram(string str1, string str2)
{
    if (str1.size() != str2.size())
        return false;

    for (int i = 0; i < str1.size(); i++)
    {
        if (str1.at(i) != str2.at(i))
        {
            return false;
        }

    }

    return true;
}
