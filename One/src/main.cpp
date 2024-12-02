#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {

  std::ifstream inputFile(
      "/Users/patrickchapple/github/adventOfCode/One/src/one.input");
  if (!inputFile) {
    std::cerr << "Error opening file!" << std::endl;
    return 1;
  }

  std::vector<int> column1;
  std::vector<int> column2;

  int value1, value2;
  while (inputFile >> value1 >> value2) {
    column1.push_back(value1);
    column2.push_back(value2);
  }
  std::sort(column1.begin(), column1.end());
  std::sort(column2.begin(), column2.end());

  inputFile.close();

  std::cout << "Column 1: ";
  for (int val : column1) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  std::cout << "Column 2: ";
  for (int val : column2) {
    std::cout << val << " ";
  }
  std::cout << std::endl;

  std::vector<int> diffs;
  int sum = 0;
  for (int i = 0; i < column1.size(); i++) {
    int diff = abs(column1[i] - column2[i]);
    diffs.push_back(diff);
    sum += diff;
  }
  std::cout << "Sum: " << sum << std::endl;
  return 0;
}
