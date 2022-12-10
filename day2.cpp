#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {

  // rock - A, X, 1 point, lose
  // paper - B, Y, 2 points, draw
  // scissors - C, Z, 3 points, win
  // 6 - win
  // 3 - draw
  // 0 - lost

  //   a b c
  // x 3 0 6
  // y 6 3 0
  // z 0 6 3

  int mat[3][3] = {{3, 0, 6}, {6, 3, 0}, {0, 6, 3}};

  //   a b c
  // x 3 1 2
  // y 1 2 3
  // z 2 3 1

  int mat2[3][3] = {{3, 1, 2},{1, 2, 3},{2, 3, 1}};

  ifstream file;
  file.open("day2.txt");

  string line = "";
  int score = 0;
  int sum1 = 0;
  int sum2 = 0;
  int points;       // 1, 2, 3
  int points_part2; // 0, 3, 6

  string elf;
  string you;

  int i, j;

  if (file.fail()) {
    cout << "file failed to open" << endl;
    return 1;
  }

  while (!file.eof()) {

    getline(file, line);

    elf = line[0];
    you = line[2];

    if (elf == "A") {
      j = 0;
    } else if (elf == "B") {
      j = 1;
    } else if (elf == "C") {
      j = 2;
    }

    if (you == "X") {
      i = 0;
      points = 1;
      points_part2 = 0;
    } else if (you == "Y") {
      i = 1;
      points = 2;
      points_part2 = 3;
    } else if (you == "Z") {
      i = 2;
      points = 3;
      points_part2 = 6;
    }

    sum1 += points;
    sum1 += mat[i][j];

    sum2 += points_part2;
    sum2 += mat2[i][j];
  }

  file.close();

  cout << "Final score in part 1: " << sum1 << endl;
  cout << "Final score in part 2: " << sum2 << endl;

  return 0;
}