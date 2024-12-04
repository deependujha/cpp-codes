# **Double Dispatch in C++**
- **Definition**: Double dispatch is a design pattern that allows a function to call another function based on the runtime types of **two** different objects. It’s often used to handle operations involving multiple object types in a type-safe and flexible way.

#### **Key Points**
1. **Problem**: In simple polymorphism, you can only dispatch based on the type of a single object. Double dispatch solves this by allowing you to decide on behavior based on the type of **two objects** involved in an operation.

2. **Common Use Case**:  
   - Common in systems where operations involve visiting different types of elements, such as an **Abstract Syntax Tree (AST)** in a compiler or a **visitor pattern** in OOP.

3. **How It Works**:
   - A base method in an object calls another method on another object, passing the `this` pointer or reference to help decide which method to invoke on the second object.
   - This results in the **second object** invoking a method on the first object, ensuring the correct overload is chosen based on their runtime types.

4. **Example**:
   - Imagine having a base `ExprAST` class with multiple derived types like `NumberExprAST`, `BinaryExprAST`, etc. Double dispatch helps in selecting the correct `codegen` function based on the type of the expression and the context of its use.

#### **Example Code**:
```cpp
#include <iostream>
using namespace std;

// Base class for expressions
class ExprAST {
public:
    virtual ~ExprAST() = default;
    virtual void accept(class Visitor& v) const = 0; // Pure virtual function for visitor pattern
};

// Derived class for NumberExpr
class NumberExprAST : public ExprAST {
public:
    int value;
    NumberExprAST(int val) : value(val) {}
    void accept(Visitor& v) const override; // Accept method for double dispatch
};

// Derived class for BinaryExpr
class BinaryExprAST : public ExprAST {
public:
    ExprAST* left;
    ExprAST* right;
    BinaryExprAST(ExprAST* l, ExprAST* r) : left(l), right(r) {}
    void accept(Visitor& v) const override; // Accept method for double dispatch
};

// Visitor class that handles different types of expressions
class Visitor {
public:
    virtual void visit(const NumberExprAST& expr) const {
        cout << "Visiting NumberExprAST with value: " << expr.value << endl;
    }
    virtual void visit(const BinaryExprAST& expr) const {
        cout << "Visiting BinaryExprAST" << endl;
        expr.left->accept(*this); // Dispatch to the left operand
        expr.right->accept(*this); // Dispatch to the right operand
    }
};

// Implementations of the accept methods
void NumberExprAST::accept(Visitor& v) const {
    v.visit(*this);
}

void BinaryExprAST::accept(Visitor& v) const {
    v.visit(*this);
}

int main() {
    NumberExprAST num(42);
    BinaryExprAST bin(&num, &num);

    Visitor visitor;
    bin.accept(visitor); // Initiates double dispatch

    return 0;
}
```

#### **Benefits**:
- **Flexibility**: Can easily extend operations without altering the existing classes.
- **Decoupling**: Allows new operations to be added without modifying the base classes, adhering to the **Open/Closed Principle**.

#### **Drawbacks**:
- **Complexity**: More intricate code due to the need for additional visitor classes.
- **Performance**: More dynamic dispatch calls can impact performance if not carefully managed.

#### **When to Use**:
- When you need to implement operations that vary based on the types of multiple objects.
- When working with the **Visitor Pattern** to implement operations on elements of a composite structure, such as ASTs in a compiler.

#### **Best Practices**:
- Keep visitor classes clean and focused on handling specific behaviors.
- Ensure classes implementing double dispatch follow the **Single Responsibility Principle** to keep code manageable.

--- 

## My code

```cpp
// Base class
class ExprAST {
public:
    virtual ~ExprAST() = default;

    // Virtual codegen function to be overridden by derived classes
    virtual llvm::Value* codegen(CodeGen& codegenObj) const = 0;
};

// Derived class example
class NumberExprAST : public ExprAST {
public:
    llvm::Value* codegen(CodeGen& codegenObj) const override {
        return codegenObj.codegen(*this);
    }
};

// CodeGen implementation
llvm::Value* CodeGen::codegen(const ast::ExprAST& exprAst) {
    // Double dispatch: calls the correct codegen implementation
    return exprAst.codegen(*this);
}

// Specialized codegen for NumberExprAST
llvm::Value* CodeGen::codegen(const ast::NumberExprAST& numExpr) {
    // Handle NumberExprAST-specific logic here
    return ...; // Generate LLVM IR
}

```
