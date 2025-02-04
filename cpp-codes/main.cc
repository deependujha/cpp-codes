#include <iostream>
#include <vector>

void printVec(std::vector<int> &v) {
  for (auto &e : v) {
    std::cout << e << ", ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  auto fn = [&v]() {
    // captured vector by value
    for (auto &e : v) {
      e = e * e;
    }
  };

  printVec(v);
  std::cout << "calling lambda fn\n";
  fn();
  std::cout << "updated vector: \n";
  printVec(v);
}
