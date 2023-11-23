#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file1, file2; // Separate fstream objects for each file.

    file1.open("file1.txt", ios::out);
    if (!file1)
    {
        cout << "File1 can't be opened" << endl;
    }
    else
    {
        file1 << "File1" << endl;
        file1.close();
    }

    file2.open("file2.txt", ios::out);
    if (!file2)
    {
        cout << "File2 can't be opened" << endl;
    }
    else
    {
        file2 << "File2" << endl;
        file2.close();
    }

    file1.open("file1.txt", ios::in);
    file2.open("file2.txt", ios::app);

    if (!file1 || !file2)
    {
        cout << "File(s) can't be opened" << endl;
    }
    else
    {
        string myText;
        while (getline(file1, myText))
        {
            file2 << myText << endl;
        }
        file1.close();
        file2.close();
    }

    return 0;
}
