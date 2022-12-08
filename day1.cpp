#include <iostream>
#include <fstream>
using namespace std;

int main()
{

    int sum = 0;
    int max = 0;

    ifstream file;
    string filename = "day1.txt";

    int line = 0;
    int value_in_line;

    file.open(filename);

    if(file.fail())
    {
        cout << "file failed to open" << endl;
        return 1;
    }

    while(!file.eof())
    {

        value_in_line = getline(file, line);

        if(!isdigit(value_in_line))
        {
            if(max < sum)
            {
                max = sum;
            }
            sum = 0;
        }
        else
        {
            sum += value_in_line;
        }

        line++;
    }

    if(max < sum)
    {
        max = sum;
    }
    sum = 0;

    cout << max << endl;

    file.close();

    return 0;
}
