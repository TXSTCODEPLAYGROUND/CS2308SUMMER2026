# Unit-04: Structs, Operator Overloading & Classes

Welcome to Unit-04! In this unit, we delve into user-defined data types and advanced object-oriented features in C++. We’ll explore how to create and use structs, implement constructors and destructors, manage access specifiers, handle pointers within structs, and harness the power of operator overloading. Along the way, you'll find detailed explanations, illustrative code examples, and numerous tricky questions—with answers—to help solidify your understanding.

---

## 1. Introduction to Structs in C++

### Overview & Concepts
A **struct** in C++ is an aggregate data type that groups together variables (called members) and functions (methods). It is very similar to a class, with one key difference:
- **Default Access:**  
  - **Struct:** Members are *public* by default.  
  - **Class:** Members are *private* by default.

### Code Example
```cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point p = {10, 20};
    cout << "Point: (" << p.x << ", " << p.y << ")" << endl;
    return 0;
}
```

### Tricky Questions
1. **Q:** What is a struct in C++?  
   **A:** A struct is a user-defined data type that groups variables and functions together; by default, its members are public.

2. **Q:** What is the primary difference between a struct and a class in C++?  
   **A:** In a struct, members are public by default, whereas in a class, they are private by default.

3. **Q:** Can a struct have member functions?  
   **A:** Yes, structs in C++ can contain member functions, constructors, destructors, and even operator overloads.

---

## 2. Constructors in Structs

### Overview & Concepts
Constructors initialize objects when they are created. Even though structs have default constructors if none are provided, defining your own allows you to set initial values and enforce invariants.

**Best Practices:**
- Use **initialization lists** for efficiency.
- Use the **`this` pointer** to resolve naming conflicts when constructor parameters share the same names as member variables.

### Code Example
```cpp
#include <iostream>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;

    // Parameterized constructor using an initialization list.
    Person(const string &name, int age) : name(name), age(age) {
        // 'this->' is optional here since names are unambiguous
        // But if parameter names were identical to member names:
        // this->name = name; this->age = age;
    }
};

int main() {
    Person person("Alice", 30);
    cout << "Name: " << person.name << ", Age: " << person.age << endl;
    return 0;
}
```

### Tricky Questions
4. **Q:** How do you define a constructor for a struct?  
   **A:** By declaring a function with the same name as the struct and initializing members (often using an initialization list).

5. **Q:** Why might you want to use the `this` pointer in a constructor?  
   **A:** To resolve naming conflicts when constructor parameters have the same names as member variables.

6. **Q:** What happens if no constructor is defined for a struct?  
   **A:** The compiler provides a default constructor that does not initialize member variables.

---

## 3. Access Specifiers in Structs and Classes

### Overview & Concepts
Access specifiers control the visibility of members. You can use:
- **public:** Accessible from anywhere.
- **private:** Accessible only within the class/struct.
- **protected:** Accessible within the class/struct and its subclasses.

### Code Example
```cpp
#include <iostream>
using namespace std;

struct Rectangle {
    // By default, members are public in a struct.
    int width;
    int height;

    // Function to compute area.
    int area() const {
        return this->width * this->height;
    }
};

class Circle {
private:
    double radius;  // private by default

public:
    Circle(double r) : radius(r) {}

    double area() const {
        return 3.14159 * radius * radius;
    }
};

int main() {
    Rectangle rect = {5, 4};
    Circle circ(3.0);

    cout << "Rectangle area: " << rect.area() << endl;
    cout << "Circle area: " << circ.area() << endl;
    return 0;
}
```

### Tricky Questions
7. **Q:** What is the default access level for members in a struct?  
   **A:** Public.

8. **Q:** What is the default access level for members in a class?  
   **A:** Private.

9. **Q:** Why might you choose to use private members in a class?  
   **A:** To encapsulate and protect data, ensuring it can only be accessed or modified through public member functions.

---

## 4. Destructors in Structs

### Overview & Concepts
A **destructor** cleans up when an object’s lifetime ends. It’s used to free resources (like dynamic memory) and perform cleanup tasks.

### Code Example
```cpp
#include <iostream>
using namespace std;

struct Resource {
    int* data;

    // Constructor: allocate dynamic memory.
    Resource() {
        data = new int[10]; // allocate an array of 10 integers
        cout << "Resource acquired." << endl;
    }

    // Destructor: deallocate dynamic memory.
    ~Resource() {
        delete[] data;
        cout << "Resource released." << endl;
    }
};

int main() {
    {
        Resource res;
        // res is in scope; its constructor is called.
    } // res goes out of scope; its destructor is automatically called.
    return 0;
}
```

### Tricky Questions
10. **Q:** When is a destructor called?  
    **A:** Automatically when an object goes out of scope or is explicitly deleted (in the case of dynamic allocation).

11. **Q:** Why is a destructor important in classes or structs that allocate dynamic memory?  
    **A:** To prevent memory leaks by ensuring that all allocated memory is properly deallocated when the object is destroyed.

---

## 5. Pointers Within Structs

### Overview & Concepts
Structs can contain pointers as members. This is useful for dynamic memory management or for linking objects together (as in linked lists).

### Code Example
```cpp
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;  // pointer to the next node

    // Constructor
    Node(int d) : data(d), next(nullptr) {}
};

int main() {
    // Create nodes dynamically.
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Traverse the list.
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Cleanup: deallocate nodes.
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    return 0;
}
```

### Tricky Questions
12. **Q:** What are the risks of using pointers within structs?  
    **A:** Risks include memory leaks, dangling pointers, and double deletion if dynamic memory is not properly managed.

13. **Q:** How can you prevent memory leaks in a struct that uses pointers?  
    **A:** Always ensure that every dynamically allocated memory (using `new`) is paired with an appropriate `delete` (or use smart pointers).

---

## 6. Operator Overloading

### Overview & Concepts
Operator overloading allows you to define custom behavior for operators (like +, -, *, etc.) when applied to user-defined types. This makes your code more intuitive and expressive.

### Why Use Operator Overloading?
- **Enhanced Readability:** Code that uses overloaded operators can look more natural.
- **Custom Behavior:** You can define how operators work with your objects.
- **Consistency:** Mimics built-in types’ behavior.

### Code Example: Overloading the + Operator for a Complex Number Struct
```cpp
#include <iostream>
using namespace std;

struct Complex {
    double real;
    double imag;

    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the + operator.
    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the += operator.
    Complex& operator+=(const Complex &other) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    // Overload the << operator for printing.
    friend ostream& operator<<(ostream &out, const Complex &c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex a(1.5, 2.0);
    Complex b(2.5, 3.0);
    Complex c = a + b; // Using operator+
    a += b;          // Using operator+=
    
    cout << "a + b = " << c << endl;
    cout << "a after += b: " << a << endl;
    return 0;
}
```

### Tricky Questions
14. **Q:** What is operator overloading, and why is it useful?  
    **A:** It is the process of defining custom behavior for operators when applied to user-defined types, making code more intuitive and easier to read.

15. **Q:** Which operators can be overloaded in C++?  
    **A:** Most operators can be overloaded, except for a few like the scope resolution operator `::`, the member access operator `.`, and the conditional operator `?:`.

16. **Q:** What is the difference between overloading operator+ and operator+=?  
    **A:** Operator+ returns a new object resulting from the addition, while operator+= modifies the object in place and returns a reference to it.

17. **Q:** Can you overload an operator as a non-member function? When might that be necessary?  
    **A:** Yes, especially for operators that require symmetry (like operator<< for streams) where the left-hand operand is not a user-defined type.

18. **Q:** What potential pitfalls should you be aware of when overloading operators?  
    **A:** Overloading operators in ways that violate user expectations or built-in behavior can lead to confusing or ambiguous code.

---

## 7. Best Practices and Additional Tips

### Overview & Concepts
When working with structs, classes, and operator overloading, consider these best practices:
- **Use the `this` pointer** to resolve naming conflicts.
- **Avoid code duplication** by leveraging initialization lists.
- **Manage dynamic memory carefully**—use smart pointers where possible.
- **Keep operator overloads intuitive:** They should behave similarly to built-in types.
- **Document your code:** Clear documentation helps users of your classes understand your design decisions.

### Tricky Questions
19. **Q:** What is the role of the `this` pointer in member functions?  
    **A:** It is a pointer to the current object instance, useful for disambiguating member names from parameters.

20. **Q:** Why might you prefer smart pointers over raw pointers in class members?  
    **A:** Smart pointers automatically manage memory, reducing the risk of leaks and dangling pointers.

21. **Q:** How do you ensure that your overloaded operators behave intuitively?  
    **A:** Follow established conventions and ensure that the operator’s behavior is consistent with that of built-in types.

22. **Q:** In which scenario might operator overloading lead to ambiguous code, and how would you resolve it?  
    **A:** Overloading operators with similar signatures or behavior can confuse users. Resolve it by ensuring clear and distinct functionality and providing comprehensive documentation.

---

## 8. Conclusion

This Unit-04 guide has provided a comprehensive look at:
- **Structs and Classes:** How to define and use them, and the differences in default access specifiers.
- **Constructors and Destructors:** Proper initialization and cleanup of objects, including dynamic memory management.
- **Access Specifiers:** Controlling member visibility to enforce encapsulation.
- **Pointers in Structs:** Using pointers effectively while avoiding pitfalls.
- **Operator Overloading:** Enhancing the intuitiveness of your custom types with clear, well-behaved operator implementations.
- **Best Practices:** Leveraging modern C++ techniques to write maintainable, efficient code.