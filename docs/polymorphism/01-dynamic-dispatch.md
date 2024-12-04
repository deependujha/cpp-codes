# **Dynamic Dispatch in C++**
- **Definition**: Dynamic dispatch is a runtime mechanism that determines which implementation of a polymorphic function to invoke when a base class pointer or reference is used.

#### **Key Points**
1. **Polymorphism Requirement**:  
   - The base class must have at least one **virtual function** to enable dynamic dispatch.
   - Derived classes override the virtual function.

2. **Virtual Table (vtable)**:  
   - C++ uses a vtable (virtual table) to resolve function calls at runtime.
   - Each polymorphic class has a vtable, and each instance stores a pointer to its class's vtable.

3. **How It Works**:
   - When calling a virtual function via a base class pointer/reference, the vtable lookup determines which derived class's function to invoke.

4. **Usage**:
   - Define virtual functions in the base class.
   - Override these functions in derived classes.

#### **Example**:
```cpp
#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    virtual void speak() const {
        cout << "Animal speaks!" << endl;
    }
    virtual ~Animal() = default; // Virtual destructor for proper cleanup
};

// Derived classes
class Dog : public Animal {
public:
    void speak() const override { // Override keyword for safety
        cout << "Dog barks!" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() const override {
        cout << "Cat meows!" << endl;
    }
};

// Runtime polymorphism
void makeAnimalSpeak(const Animal& animal) {
    animal.speak(); // Resolved at runtime
}

int main() {
    Dog dog;
    Cat cat;

    makeAnimalSpeak(dog); // Output: Dog barks!
    makeAnimalSpeak(cat); // Output: Cat meows!
    return 0;
}
```

#### **When to Use**:
- When you need **runtime polymorphism**, such as in plugin systems, AST evaluation, game engines, or any scenario requiring behavior selection based on object type at runtime.

#### **Best Practices**:
- Always use `override` keyword to ensure correct function overriding.
- Prefer `dynamic_cast` when you need safe downcasting.
- Use virtual destructors in base classes to prevent resource leaks.

--- 

## My code

```cpp
llvm::Value* CodeGen::codegen(const ast::ExprAST& exprAst) {
    enum ExprAstType {
        NumberExpr,
        VariableExpr,
        BinaryExpr,
        CallExpr,
        Invalid,
    };

    ExprAstType e = Invalid;
    if (typeid(exprAst) == typeid(ast::BinaryExprAST)) e = BinaryExpr;
    else if (typeid(exprAst) == typeid(ast::NumberExprAST)) e = NumberExpr;
    else if (typeid(exprAst) == typeid(ast::VariableExprAST)) e = VariableExpr;
    else if (typeid(exprAst) == typeid(ast::CallExprAST)) e = CallExpr;

    switch (e) {
        default:
            return nullptr;
        case NumberExpr: {
            // Dynamic cast to derived class
            const auto* numExpr = dynamic_cast<const ast::NumberExprAST*>(&exprAst);
            if (numExpr) return codegen(*numExpr);
            break;
        }
        case BinaryExpr: {
            const auto* binExpr = dynamic_cast<const ast::BinaryExprAST*>(&exprAst);
            if (binExpr) return codegen(*binExpr);
            break;
        }
        case VariableExpr: {
            const auto* varExpr = dynamic_cast<const ast::VariableExprAST*>(&exprAst);
            if (varExpr) return codegen(*varExpr);
            break;
        }
        case CallExpr: {
            const auto* callExpr = dynamic_cast<const ast::CallExprAST*>(&exprAst);
            if (callExpr) return codegen(*callExpr);
            break;
        }
    }

    return nullptr;
}
```
