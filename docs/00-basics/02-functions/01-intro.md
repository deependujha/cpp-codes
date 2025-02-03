# Functions in C++

## Simple Example

```cpp
#include <iostream>

std::string greet(std::string x){
    return "Hello, " + x + "!";
}

int main(){
    std::cout<<greet("Deep")<<"\n";
}
```

---

## Function overloading

- multiple functions can have the same name with different parameters.

```cpp
int plusFuncInt(int x, int y) {
  return x + y;
}

double plusFuncDouble(double x, double y) {
  return x + y;
}

int main() {
  int myNum1 = plusFuncInt(8, 5);
  double myNum2 = plusFuncDouble(4.3, 6.26);
  cout << "Int: " << myNum1 << "\n";
  cout << "Double: " << myNum2;
  return 0;
}
```

!!! danger
    - You can't overload a function with same name, same parameter numbers and type, but different return type.

!!! bug "Function overloading compile-time V/S Runtime performance"
    - `Function Overloading` requires the compiler to perform **name mangling** on the function name to include information about the argument types.

    > name mangling: modifying name (`List_my.get` -> `List__my_get`)

    - Since, name mangling is done at compile-time, so **compile time increases**.
    - But, during **runtime**, function (with mangled name) is called directly, so **no performance penalty**.

---

## Function Overloading V/S Overriding

- `function overloading` means having multiple functions with same name, but different parameter count or types.
- `function/method overriding` is when we override a base/default method present in base class in an inherited derived class.
