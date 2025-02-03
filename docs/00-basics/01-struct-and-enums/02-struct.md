# Structs

- structs are a way to group related data together
- they are useful when you want to create a custom data type that has multiple fields
- structs are defined using the `struct` keyword

```cpp
#include <iostream>
using namespace std;
struct Point {
  int x;
  int y;
};

int main() {
  Point p1 = {1, 2}; // method: 1
  Point p2 = {.x = 3, .y = 4}; // method: 2
  cout << p1.x << " " << p1.y << endl;
  cout << p2.x << " " << p2.y << endl;
  return 0;
}
```

!!! Warning ""
    - Both ways of instantiating a struct are correct in C++.  

    - `Point p1 = {1, 2};`
        - This is **aggregate initialization**, which initializes struct members in order.  
        - Works in both C and C++.

    - `Point p2 = {.x = 3, .y = 4};`  
        - This is **designated initialization**, which allows initializing specific members explicitly.  
        - **C++20 and later only** (not valid in C++17 or earlier).  

    If you're using **C++17 or older**, `p2` will cause a compilation error.

---

## Functions in Structs

- functions can be defined inside structs
- they can be used to access the fields of the struct
- functions can be defined with the `static` keyword to make them accessible **`without creating struct variable`**.

```cpp
#include <iostream>
using namespace std;
struct Point
{
    int x;
    int y;

    void init(int x, int y){
        this->x = x;
        this->y = y;
    }
    static int getX(Point p)
    {
        return p.x;
    }

    static double getPi()
    {
        return 3.1415;
    }
};

int main()
{
    Point p;
    p.init(1, 2);
    cout << Point::getX(p) << endl;
    return 0;
}
```

---

## Constructor and Destructor in Structs

- constructors and destructors are special functions that are called when an object is created and destroyed, respectively
- they are defined inside the struct
- **Constructors** => Same name as the struct
- **Destructors** => Same name as the struct, but with an extra `~` at the start

```cpp
#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) {
        cout << "constructor called" << endl;
    }
    ~Point() {
        cout << "destructor called" << endl;
    }

    void distanceFromOrigin() {
        cout << "distance from origin: " << sqrt(x * x + y * y) << endl;
    }
};

int main()
{
    Point p(1, 2);
    p.distanceFromOrigin();
    return 0;
}
```

---

## Initializer List

- initializer lists are a way to initialize the fields of a struct
- they are defined using the `:` operator
- they are useful to separate the initialization code from the main constructor body to **help developers focus on what special functionality the constructor provides rather than the boilerplate code**

```cpp
struct Point
{
    int x;
    int y;

    // below `: x(x), y(y)` is the initializer list

    Point(int x, int y) : x(x), y(y) {}
};
```

---

## Creating instances of Structs with Struct declarations

```cpp
struct Point
{
    int x;
    int y;

    // below `: x(x), y(y)` is the initializer list
    Point(int x, int y) : x(x), y(y) {}

}p1(1,2), p2(3,4);
// p1 and p2 are instances of the Point struct
```
