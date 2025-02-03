# Function Pointers

- Function pointers are a way to store a reference to a function.
- They are useful when you want to pass a function as an argument to another function.

```cpp
#include <iostream>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

int main()
{
    auto my_add = add;
    // auto ==> int (*my_add)(int, int)
    // int (*my_add)(int, int) = add;

    cout << my_add(2, 3) << endl;
    return 0;
}
```

- Mostly, **`auto`** keyword is used to infer the type of the function pointer.
- In the above example, the type of the function pointer is `int (*)(int, int)`.

---

## Passing a function pointer as an argument

```cpp
#include <iostream>
#include <vector>
using namespace std;

void forEach(vector<int> v, void (*f)(int)) // function pointer
{
    for (auto i : v)
    {
        f(i);
    }
}

void printVal(int i)
{
    cout << "value is: " << i << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    forEach(v, printVal);
    return 0;
}
```

---

## Lambda functions

- If all you need to do is to pass a function to another function, then instead of creating a function in global space, you can create a function in the local scope.
- This anonymous function (a function without a name) is called `lambda function`.
- `lambda functions` can `capture values from surrounding scope`.

```cpp
#include <iostream>
#include <vector>
using namespace std;

void forEach(vector<int> v, void (*f)(int))
{
    for (auto i : v)
    {
        f(i);
    }
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    forEach(v, [](int i) {
        cout << "value is: " << i << endl;
    });
    return 0;
}
```
