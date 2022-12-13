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
    char *c;
    c = NULL;

    int x, y = 0;
    string line = "";
    string top = "";

    if (file.fail()) {
        cout << "file failed to open" << endl;
        return 1;
    }

    getline(file, line);
    x = line.length();

    int alen = ((x-3)/4)+1;
    stack<char> array[alen];

    file.seekg(0);

    getline(file, line);

    // filling the stack
    while(line != "" && !file.eof()){
        for(int i=0; i < alen; i++){
            array[i].push(line[i+1+(i*3)]);
        }
        getline(file, line);
    }

    // remove the numbers
    for(int i=0; i<alen; i++){
        array[i].pop();
    }

    // reverse Stack
    stack<char> arr[alen];

    for(int i=0; i<alen; i++){
        reverseStack(array[i], arr[i]);
    }

    for(int i=0; i<alen; i++){
            cout << arr[i].top() << " ";
    }

    //delete[] array;

    while (!file.eof()) {

        string num = "";
        int howMuch = 0;
        int from = 0;
        int to = 0;

        getline(file, line, ' ');

        getline(file, num, ' ');
        howMuch = stoi(num);

        getline(file, line, ' ');

        getline(file, num, ' ');
        from = stoi(num);

        getline(file, line, ' ');

        getline(file, num, '\n');
        to = stoi(num);

        cout << howMuch << " " << from << " " << to << " " << endl;
        for(int i=0; i<alen; i++){
            cout << arr[i].top() << " ";
        }
        cout << endl;

        // for(int i=0; i<howMuch; i++){
        //     char temp = arr[from-1].top();
        //     arr[from-1].pop();
        //     arr[to-1].push(temp);
        // }
    }

    file.close();

    cout << endl << x << ((x-3)/4)+1 << endl;

    for(int i=0; i<alen; i++){
        top += arr[i].top();
        cout << arr[i].top() << " ";
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