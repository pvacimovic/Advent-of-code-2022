#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    
    ifstream file;
    file.open("day4.txt");
    int b = 0;

    string line = "";
    string num = "";
    char *c;
    int sum = 0;
    int sum2 = 0;

    if (file.fail()) {
        cout << "file failed to open" << endl;
        return 1;
    }

    while (!file.eof()) {

        string arrS[4] = {""}; // to store four numbers as strings
        int arr[4] = {0}; // to store four intigers

        getline(file, line);

        c = &line[0];

        //first num
        while(*c != ','){
            if(isdigit(*c)){
                num += *c;
            }
            else{
                num += " ";
            }
            c++;
        }
        c++;
        num += " ";
        // second num
        while(isdigit(*c) || *c == '-'){
            if(isdigit(*c)){
                num += *c;
            }
            else{
                num += " ";
            }
            c++;
        }

        // num has format: number number number number
        int j = 0; // to go through arr
        for(int i=0; i<num.length(); i++){
            if(num[i] == ' '){
                j++;
            }
            else{
                arrS[j]+=num[i];
            }
        }
        
        for(int i=0; i<4; i++){
            arr[i] = stoi(arrS[i]);
        }

        // arr[] have four intigers now

        int num1 = arr[0];
        int num2 = arr[1];
        int num3 = arr[2];
        int num4 = arr[3];

        // part 1

        if(num1 < num3 && num2 >= num4){
            sum += 1;
        }
        else if(num1 > num3 && num2 <= num4){
            sum += 1;
        }
        else if(num1 == num3){
            sum += 1;
        }
        else{
            sum += 0;
        }

        // part 2

        if(num1 <= num4 && num1 >= num3 || num2 <= num4 && num2 >= num3){
            sum2 += 1;
        }
        else if(num3 <= num2 && num3 >= num1 || num4 <= num2 && num4 >= num1){
            sum2 += 1;
        }

        //cout << b << " " << line << " " << *c << endl;
        //cout << b << " " << line << " = " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << endl;

        num = "";
    }

    file.close();

    cout << "Part1: Pairs where one fully contain the other: " << sum << endl;
    cout << "Part2: Pairs where one fully contain the other: " << sum2 << endl;

    return 0;
}
