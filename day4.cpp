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
    int sum=0;

    if (file.fail()) {
        cout << "file failed to open" << endl;
        return 1;
    }

    while (!file.eof()) {

        string arrS[4] = {""}; // to store four numbers as strings
        int arr[4] = {0}; // to store four intigers

        //b++;
        // int mat[2][99];
        // for (int i = 0; i < 2; i++) {
        //     for (int j = 0; j < 99; j++) {
        //     mat[i][j] = 0;
        //     }
        // }  

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

        // // filling matrix with 0 and 1
        // for(int j=0; j<99; j++){

        //     if(j>=arr[0]){
        //         mat[0][j] = 1;
        //     }

        //     if(j>arr[1]){
        //         mat[0][j] = 0;
        //     }
        //     if(j>=arr[2]){
        //         mat[1][j] = 1;
        //     }

        //     if(j>arr[3]){
        //         mat[1][j] = 0;
        //     }
        // }

        // if(arr[0] > arr[2]){
        //     if(mat[0][arr[0]]==1 && mat[1][arr[0]]==1 && mat[0][arr[1]]==1 && mat[1][arr[1]]==1){
        //         sum += 1;
        //     }
        // }
        // else if(arr[0] < arr[2]){
        //     if(mat[0][arr[2]]==1 && mat[1][arr[2]]==1 && mat[0][arr[3]]==1 && mat[1][arr[3]]==1){
        //         sum += 1;
        //     }
        // }
        // else{
        //     sum += 1;
        // }

        //cout << b << " " << line << " " << *c << endl;
        //cout << b << " " << line << " = " << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << endl;

        num = "";
    }

    file.close();

    cout << "Part1: Pairs where one fully contain the other: " << sum << endl;
    // cout << "Part 2 - Sum of priorities: " << sum2 << endl;

    return 0;
}
