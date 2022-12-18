#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    
    ifstream file;
    file.open("day6.txt");

    string signal = "";


    if (file.fail()) {
        cout << "file failed to open" << endl;
        return 1;
    }

    getline(file, signal);

    char *c = &signal[3];
    int b = 3;
    char part2[26] = {0};
    char buff[14];

    for(int i; i<14; i++){
        buff[i] = signal[i];
        part2[static_cast<int>(signal[i])-'97'] = 1;
    }

    // part 1
    while(isalpha(*c))
    {
        if(*(c-3)!=*(c-2) && *(c-3)!=*(c-1) && *(c-3)!=*(c) &&
            *(c-2)!=*(c-1) && *(c-2)!=*(c) && *(c-1)!=*(c)){
                break;
            }
        c++;
        b++;
    }

    file.seekg(0);

    // part 2
    for(int i=14; i < signal.length(); i++){
        
    }

    file.close();

    cout << "Part1: Characters needed: " << b + 1 << endl;
    cout << "Part2: Characters needed: " << b + 1 << endl;

    return 0;
}
