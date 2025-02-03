# Function Variable

- Sometimes, you need to store a function in a variable that you can call later.
- For example, [DeepTensor (a minimal pytorch like autograd framework)'s Value object](https://github.com/deependujha/DeepTensor/blob/main/csrc/value.h) requires `backward_` variable, that stores the function to be called when `value::backward()` is called.

---

## Older way (before C++11)

- Before C++11, we used to use `function-pointers`.

```cpp
#include <iostream>

int sum(int a, int b){
    return a+b;
}

int main(){
    int(*fn)(int, int) = nullptr;
    if(!fn){
        std::cout<<"fn is null.\n";
    }

    fn = sum;
    std::cout<<"calling fn: "<<fn(2,3)<<"\n";

}
```

---

## After C++11

- From C++11 you can use std::function to store functions.

```txt
std::function<return_type(parameter_type1, parameter_type2, ...)>
```

```cpp
#include <iostream>

int sum(int a, int b){
    return a+b;
}

int main(){
    std::function<int(int, int)> fn = nullptr;
    if(!fn){
        std::cout<<"fn is null.\n";
    }

    fn = sum;
    std::cout<<"calling fn: "<<fn(2,3)<<"\n";

}
```
