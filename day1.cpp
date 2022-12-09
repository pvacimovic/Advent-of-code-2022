#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isInArray(int number, int* array, int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == number)
        {
            return true;
        }
    }
    return false;
}

int main() {

    ifstream file;
    file.open("day1.txt");

    int value_in_line = 0;
    string lines = "";
    int sum = 0;
    int max = 0, max2 = 0, max3 = 0, prev = 0;
    int line;
    int maxes[3] = {0, 0, 0};

    if(file.fail())
    {
        cout << "file failed to open" << endl;
        return 1;
    }

    for(int i=0; i<3; i++) // needed first 3 max
    {   
        cout << "try " << i << endl;

        while(!file.eof())
        {
            getline(file, lines);

            if(lines=="")
            {
                if(max < sum)
                {
                    prev = max;
                    max = sum;
                    if(!isInArray(max, maxes, 3))
                    {
                        maxes[i] = max;
                    }
                    else
                    {
                        max = prev;
                    }
                }
                sum = 0;
            }
            else
            {
                sum += stoi(lines);
            }

        }

        // just to check the last section
        if(max < sum)
        {
            prev = max;
            max = sum;
            if(!isInArray(max, maxes, 3))
            {
                maxes[i] = max;
            }
            else
            {
                max = prev;
            }
        }

        sum = 0;
        max = 0;
        
        file.seekg(0); // move to the beggining to a file
    }

    file.close();

    int part2 = maxes[0] + maxes[1] + maxes[2];

    cout << "Maximum sum: " << maxes[0] << endl;
    cout << "Top 3 max sums: " << part2 << endl;

    return 0;
}
