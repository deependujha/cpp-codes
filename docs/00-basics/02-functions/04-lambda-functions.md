# Lambda functions (`closure`)

- C++ 11 introduced lambda expressions
- allow inline functions which can be used for short snippets of code that are not going to be reused and therefore do not require a name.

```txt
[ capture clause ] (parameters) -> return-type  
{   
   definition of method   
} 
```

- Generally, the `return-type in lambda expressions is evaluated by the compiler itself` and we don’t need to specify it explicitly. Also the `-> return-type part can be ignored`.

- However, in some complex cases e.g. conditional statements, the compiler can’t determine the return type and explicit specification is required.

---

## Capture clause

- A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope.

!!! info "Capture variables for lambda functions"
    - Capture by reference
    - Capture by value
    - Capture by both (mixed capture)

!!! success "Syntax used for capturing variables"
    - [&] : capture all external variables by reference
    - [=] : capture all external variables by value
    - [a, &b] : capture a by value and b by reference
    - [=, &b] : capture all variables by value, and b by reference
    - [] : don't capture any variable
    - [this, ...] : **Capture raw pointer this (DANGEROUS!)**. Can't prevent `use after deletion bug`
    - [self = shared_from_this(), ...] : **Capture shared_ptr to this (SAFE!)**

!!! bug "`this` v/s `shared_from_this()`"
    TL;DR:

    - Use `[this]` only if you're sure the object won't be deleted.
    - Use `[self = shared_from_this()]` to prevent dangling pointers in async code. 🚀

---

## Code

- **map function:** lambda function to square all numbers of the array and return new array.

```cpp
#include <functional>
#include <iostream>
#include <vector>

int sum(int a, int b) { return a + b; }

std::vector<int> forEach(std::vector<int> v, std::function<int(int)> fn) {
  std::vector<int> v_sq;
  for (auto &e : v) {
    v_sq.push_back(fn(e));
  }
  return v_sq;
}

void printVec(std::vector<int> &v) {
  for (auto &e : v) {
    std::cout << e << ", ";
  }
  std::cout << "\n";
}
int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  std::vector<int> v_sq = forEach(v, [](int i) { return i * i; });
  printVec(v);
  printVec(v_sq);
}
```

---

## Code for capturing value

```cpp
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
    // captured vector by reference
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
```
