#include <fstream>
#include <iostream>
#include <string>
using namespace std;

char compare(string, string, int);

int main() {

    ifstream file;
    file.open("day3.txt");
    int b = 1;

    string line = "";
    int length;
    string strings[3];

    char target;
    int points;
    int sum=0;

    int sum2=0;

    if (file.fail()) {
        cout << "file failed to open" << endl;
        return 1;
    }

    // part2
    while (!file.eof()) {

        int mat[3][52];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 52; j++) {
            mat[i][j] = 0;
            }
        }       

        for(int i=0; i<3; i++){

            getline(file, line);

            strings[i] = line;

            for(int j=0; j<strings[i].length(); j++){

                if(islower(strings[i][j])){
                    mat[i][(static_cast<int>(strings[i][j])-97)] = 1;
                }
                else{
                    mat[i][(static_cast<int>(strings[i][j])-39)] = 1;
                }
            }

        }

        for(int i=0; i<52; i++){
            if(mat[0][i]==1 && mat[0][i]==mat[1][i] && mat[0][i]==mat[2][i]){
                // cout << b++ << ": " << i << endl;
                sum2 += (i+1);
            }
        }
    }

    file.seekg(0); // move to the beggining to a file

    // part 1
    while (!file.eof()) {

        getline(file, line);

        length = line.length();

        int startIndex = length / 2;

        string firstHalf = line.substr(0, startIndex);
        string secondHalf = line.substr(startIndex);

        target = compare(firstHalf, secondHalf, length/2);

        if(islower(target)){
            points = static_cast<int>(target) - 96;
        }
        else{
            points = static_cast<int>(target) - 38;
        }

        sum += points;
        // cout << b++ << " " << line << " = " << firstHalf << " + " << secondHalf << " -- " << target << ": " << points << endl;

        line = "";
    }

    file.close();

    cout << "Part 1 - Sum of priorities: " << sum << endl;
    cout << "Part 2 - Sum of priorities: " << sum2 << endl;

    return 0;
}

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