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