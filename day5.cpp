#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <stack>
#include <cstdlib>
using namespace std;

void reverseStack(stack<char>&, stack<char>&);

int main(){

    ifstream file;
    file.open("day5.txt");
    int b = 0;

    int x, y = 0;
    string line = "";
    string top = "";

    if (file.fail()) {
        cout << "file failed to open" << endl;
        return 1;
    }

    getline(file, line);
    x = line.length();

    // x and y help to determine size of this data structu 

    int alen = ((x-3)/4)+1;
    stack<char> array[alen];

    file.seekg(0);

    // filling the stack
    while(line != "" && !file.eof()){
        getline(file, line);
        for(int i=0; i < alen; i++){
            array[i].push(line[i+2+(i*3)]);
        }
    }

    // remove the numbers
    for(int i=0; i<alen; i++){
        array[i].pop();
    }

    // reverse Stack
    stack<char> arr[alen];

    for(int i=0; i< alen; i++){
        reverseStack(array[i], arr[i]);
    }

    while (!file.eof()) {

        getline(file, line);

        // doesn't work - need even numbers >9
        // figure out how to get these three numbers and you are good
        int howMuch = (line[5]);
        int from = line[12];
        int to = line[17];

        for(int i=0; i<howMuch; i++){
            char temp = arr[from].top();
            arr[from].pop();
            arr[to].push(temp);
        }
    }

    file.close();

    cout << endl << x << ((x-3)/4)+1 << endl;;

    for(int i=0; i<alen; i++){
        top += arr[i].top();
    }

    cout << "Part1: Top of stacks: " << top << endl;
    // cout << "Part2:  " << endl;

    return 0;


}

// Recursive function to reverse the stack
void reverseStack(stack<char>& s, stack<char>& r) {
  if (s.empty()) {
    return; 
  }
  char top = s.top();
  s.pop();

  reverseStack(s, r);

  r.push(top);
}