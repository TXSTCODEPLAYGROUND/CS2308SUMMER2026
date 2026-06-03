# Unit-08: Classes – An OO Design

Welcome to Unit-08! In this unit, we dive deep into Object-Oriented Programming (OOP) in C++ and explore how to design robust, modular, and reusable software using classes. We cover the four pillars of OOP—Encapsulation, Inheritance, Polymorphism, and Abstraction—along with advanced topics such as method resolution, virtual functions (pure and non-pure), and basic exception handling. You'll find detailed explanations, code examples, and plenty of tricky questions to test and reinforce your understanding.

---

## 1. Object-Oriented Programming: The Big Picture

### Overview & Concepts
OOP in C++ revolves around four fundamental concepts:
- **Encapsulation:** Bundling data and methods into a single unit (a class) and restricting access to some of the object's components using access specifiers (public, protected, private).
- **Inheritance:** Creating a new class (derived class) that reuses, extends, or modifies the behavior of an existing class (base class).
- **Polymorphism:** Allowing methods to have different behaviors based on the object they are acting upon, primarily achieved through virtual functions and method overriding.
- **Abstraction:** Hiding complex implementation details and exposing only the necessary components. Abstract classes (with pure virtual functions) and interfaces are key to achieving this.

### Tricky Questions
1. **Q:** What are the four pillars of OOP in C++?  
   **A:** Encapsulation, Inheritance, Polymorphism, and Abstraction.

2. **Q:** How does encapsulation contribute to code maintainability?  
   **A:** It hides implementation details and exposes only what is necessary, which reduces dependencies and potential errors when modifying code.

---

## 2. Encapsulation

### Overview & Concepts
Encapsulation means bundling data (attributes) and methods (functions) into a class and controlling access to them. Access specifiers—**public**, **protected**, and **private**—play a crucial role:
- **Public:** Accessible from anywhere.
- **Protected:** Accessible within the class and its derived classes.
- **Private:** Accessible only within the class itself.

### Code Example: Encapsulation
```cpp
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
    double balance;  // Hidden data

public:
    Account(double initialBalance) : balance(initialBalance) {}

    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) balance -= amount;
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    Account myAccount(100.0);
    myAccount.deposit(50.0);
    myAccount.withdraw(30.0);
    cout << "Current balance: $" << myAccount.getBalance() << endl;
    return 0;
}
```

### Tricky Questions
3. **Q:** Why are data members usually declared as private in a class?  
   **A:** To enforce encapsulation, ensuring that data can only be modified through controlled methods.

4. **Q:** How can you access a private member from outside the class?  
   **A:** Direct access is not allowed; you must use public getter/setter functions provided by the class.

---

## 3. Inheritance

### Overview & Concepts
Inheritance enables the creation of a new class (derived class) from an existing class (base class), promoting code reuse and establishing a natural hierarchy.

### Code Example: Inheritance and Method Resolution
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() const { cout << "Animal sound" << endl; }
    virtual ~Animal() {}  // Virtual destructor for proper cleanup
};

class Dog : public Animal {
public:
    void speak() const override { cout << "Woof!" << endl; }

    // Call base class function explicitly using scope resolution
    void makeGenericSound() const {
        Animal::speak();  // Calls Animal's speak()
    }
};

int main() {
    Dog dog;
    dog.speak();          // Outputs: Woof!
    dog.makeGenericSound(); // Outputs: Animal sound
    return 0;
}
```

### Tricky Questions
5. **Q:** What is the benefit of inheritance in OOP?  
   **A:** It promotes code reuse by allowing derived classes to inherit and extend the functionality of base classes.

6. **Q:** How do you call a base class function from a derived class if it has been overridden?  
   **A:** Use the scope resolution operator (e.g., `BaseClass::function()`).

7. **Q:** Why is a virtual destructor important in a base class?  
   **A:** It ensures that the correct destructor is called for derived classes, preventing resource leaks.

---

## 4. Polymorphism

### Overview & Concepts
Polymorphism allows functions to behave differently based on the object type that invokes them. This is primarily achieved through virtual functions and function overriding.

### Code Example: Polymorphism with Virtual Functions
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() const {
        cout << "Drawing a generic shape." << endl;
    }
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a circle." << endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing a square." << endl;
    }
};

void render(const Shape& shape) {
    shape.draw();  // Calls the appropriate draw() based on object type
}

int main() {
    Circle circle;
    Square square;
    render(circle);
    render(square);
    return 0;
}
```

### Tricky Questions
8. **Q:** What is runtime polymorphism, and how is it achieved in C++?  
   **A:** It is the ability of a function to call the correct overridden method at runtime, achieved through virtual functions.

9. **Q:** What would happen if the `draw()` function in `Shape` were not declared as virtual?  
   **A:** The base class version would be called, even if the object is of a derived type, defeating polymorphism.

---

## 5. Abstraction

### Overview & Concepts
Abstraction involves hiding complex implementation details and exposing only the necessary features. In C++, abstract classes (with pure virtual functions) enforce that derived classes implement specific functionality.

### Pure vs. Non-Pure Virtual Functions
- **Non-Pure Virtual Function:** Has a default implementation; derived classes can override it.
- **Pure Virtual Function:** Declared by appending `= 0` and has no implementation in the base class, making the class abstract.

### Code Example: Abstract Class and Pure Virtual Function
```cpp
#include <iostream>
using namespace std;

class Employee {
public:
    virtual void work() const = 0;  // Pure virtual function
    virtual ~Employee() {}
};

class Developer : public Employee {
public:
    void work() const override {
        cout << "Writing code." << endl;
    }
};

int main() {
    // Employee emp; // Error: Cannot instantiate abstract class
    Employee* dev = new Developer();
    dev->work();  // Outputs: Writing code.
    delete dev;
    return 0;
}
```

### Tricky Questions
10. **Q:** What is a pure virtual function, and how is it declared in C++?  
    **A:** A function declared with `= 0` in a base class, making it abstract and requiring derived classes to provide an implementation.

11. **Q:** What is the difference between a pure virtual function and a non-pure virtual function?  
    **A:** A pure virtual function has no implementation in the base class and forces derived classes to override it, while a non-pure virtual function has a default implementation that can be overridden.

12. **Q:** Why would you use an abstract class?  
    **A:** To define an interface for a set of classes, ensuring that derived classes implement specific functions.

13. **Q:** How does abstraction help in reducing complexity in large systems?  
    **A:** It hides implementation details and exposes only essential features, making systems easier to understand, maintain, and extend.

---

## 6. Exception Handling (Self-Study)

### Overview & Concepts
Exception handling in C++ enables graceful error management using `try`, `catch`, and `throw`. Though not the primary focus of OOP design, it's an essential part of robust application development.

### Quick Example: Exception Handling
```cpp
#include <iostream>
using namespace std;

int divide(int a, int b) {
    if (b == 0)
        throw "Division by zero error!";
    return a / b;
}

int main() {
    try {
        cout << "Result: " << divide(10, 0) << endl;
    } catch (const char* e) {
        cout << "Caught exception: " << e << endl;
    }
    return 0;
}
```

### Tricky Questions
14. **Q:** What keywords are used in C++ for exception handling?  
    **A:** `try`, `catch`, and `throw`.

15. **Q:** What happens when an exception is thrown and not caught?  
    **A:** The program terminates with an uncaught exception error.

16. **Q:** How can exception handling improve the robustness of your programs?  
    **A:** It allows you to handle errors gracefully and maintain control of the program flow instead of crashing unexpectedly.

---

## 7. Additional Tricky Questions on OOP Concepts

17. **Q:** Explain method overriding in the context of inheritance and polymorphism.  
    **A:** Method overriding occurs when a derived class provides its own implementation of a virtual function defined in its base class, allowing polymorphic behavior.

18. **Q:** How can you enforce that a derived class implements a specific method?  
    **A:** By declaring the method as pure virtual in the base class.

19. **Q:** What is method resolution, and how can you invoke a base class method from an overridden method in the derived class?  
    **A:** Method resolution determines which function implementation to call. In C++, you can call the base class version by using the scope resolution operator (e.g., `Base::function()`).

20. **Q:** How does using virtual destructors in a base class prevent resource leaks?  
    **A:** Virtual destructors ensure that when a derived object is deleted through a base pointer, the derived class’s destructor is called, properly cleaning up resources.

21. **Q:** What are the benefits of combining exception handling with OOP?  
    **A:** It helps create robust, fault-tolerant classes that can manage and recover from errors without crashing the entire application.

---

## 8. Conclusion

This Unit-08 guide has explored the principles of Object-Oriented Design in C++:
- **Encapsulation:** Bundling data and methods and controlling access with access specifiers.
- **Inheritance:** Reusing and extending existing code to create new classes, with a focus on method resolution.
- **Polymorphism:** Achieving dynamic behavior through virtual functions and method overriding.
- **Abstraction:** Hiding complex details and enforcing contracts via abstract classes and pure virtual functions.
- **Exception Handling:** An essential aspect for building robust, real-world applications.