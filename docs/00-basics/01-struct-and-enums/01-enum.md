# Enums (Enumeration)

- if you have a finite set of values, use an enum instead of using a number and remembering what each number means
- for example, if you have a set of days of the week, you can use an enum to represent that, instead of using numbers from (0-6)
- enums are a type of data structure that is used to define a set of named constants

---

## Simple Code

```cpp
#include <iostream>
using namespace std;

enum LogLevel : unsigned int // define datatype (can be any integer type)
{
    DEBUG, // 0
    ERROR, // 1
    INFO,  // 2
    WARNING // 3
};

int main()
{
    LogLevel level = DEBUG;
    cout << level << endl;

    LogLevel level2 = LogLevel::INFO;

    cout << level2 << endl;
    return 0;
}
```

---

## Change Enum values

```cpp
#include <iostream>
using namespace std;

enum Level {
  LOW = 25,
  MEDIUM = 50,
  HIGH = 75
};

int main()
{
    LogLevel level = DEBUG;
    cout << level << endl;

    LogLevel level2 = LogLevel::INFO;

    cout << level2 << endl;
    return 0;
}
```

---

## Change Enum `starting value`

- if we assign a value to one specific item, the next items will update their numbers accordingly:

```cpp
enum Level {
  LOW = 5,
  MEDIUM, // Now 6
  HIGH // Now 7
};
```

---

## Enum in Switch

```cpp
enum Level {
  LOW = 1,
  MEDIUM,
  HIGH
};

int main() {
  enum Level myVar = MEDIUM;

  switch (myVar) {
    case 1:
      cout << "Low Level";
      break;
    case 2:
      cout << "Medium level";
      break;
    case 3:
      cout << "High level";
      break;
  }

  cout << "===========================\n";

  switch (myVar) {
    case LOW:
      cout << "Low Level";
      break;
    case MEDIUM:
      cout << "Medium level";
      break;
    case HIGH:
      cout << "High level";
      break;
  }

  cout<<"\n";
  return 0;
}
```
