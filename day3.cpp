#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char compare(string first, string second, int len)
{
    char t = 'A';

    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(first[i]==second[j]){
                t = first[i];
            }
        }
    }
    return t;
}

int main() {

    ifstream file;
    file.open("day3.txt");

    string line = "";
    int length;
    int j = 1;

    char target;
    int points;
    int sum=0;

    if (file.fail()) {
        cout << "file failed to open" << endl;
        return 1;
    }

    while (!file.eof()) {

        getline(file, line);

        length = line.length();

        int startIndex = length / 2;

        string firstHalf = line.substr(0, startIndex);
        string secondHalf = line.substr(startIndex);

        target = compare(firstHalf, secondHalf, length);

        if(islower(target)){
            points = static_cast<int>(target) - 96;
        }
        else{
            points = static_cast<int>(target) - 38;
        }

        sum += points;
        cout << j << " " << line << " = " << firstHalf << " + " << secondHalf << " -- " << target << ": " << points << endl;
        j++;

        line = "";
        target = NULL;
    }

    file.close();

    cout << "Sum of priorities: " << sum << endl;

    return 0;
}