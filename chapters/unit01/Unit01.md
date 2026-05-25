# Unit-01: Basics of C++ Programming and Data Structures

Welcome to Unit-01, a comprehensive introduction to the fundamental concepts of C++ programming and its data structures. In this unit, you'll learn about functions, variable scope, code organization, arrays, and the Standard Template Library (STL) data structures such as vectors, lists, stacks, maps, and strings. Each section begins with an introduction and detailed explanations, enriched with full code examples, real-world use cases, and Q&A sections to clarify common doubts. Additionally, for every data structure, you’ll find a comprehensive table outlining all the key member functions available.

---

## 1. Functions

### **Introduction**
Functions are the building blocks of any C++ program. They encapsulate blocks of code into reusable units, making your code modular, maintainable, and easier to understand.

### **Core Concepts & Explanations**
- **Function Signature:**  
  A function’s signature comprises its name, the list of parameters, and its return type. Functions can be classified as:
  - **With Arguments, No Return:** Processes inputs and performs an action.
  - **With Arguments, With Return:** Processes inputs and returns a computed value.
  - **Without Arguments, With Return:** Doesn’t need input but returns a value.
  - **Without Arguments, No Return:** Performs a task without input or returning a value.
  
- **Additional Types:**  
  - **Recursive Functions:** Call themselves to solve a problem incrementally.
  - **Inline Functions:** Suggest the compiler to embed the function code at the point of call, reducing overhead.
  - **Function Overloading:** Multiple functions sharing the same name but differing in parameter types.
  - **Lambda Functions (C++11+):** Anonymous functions for short-term use, ideal for callbacks and quick operations.

### **Code Examples & Q&A**

**Example 1: Function with Arguments, No Return**
```cpp
#include <iostream>
using namespace std;

void printSum(int a, int b) {
    cout << "Sum is: " << (a + b) << endl;
}

int main() {
    printSum(3, 5);  // Output: Sum is: 8
    return 0;
}
```

- **Q:** Why would you choose a function that does not return a value?  
  **A:** It’s useful when the purpose is to perform an action (like printing or modifying global state) rather than computing a value.

**Example 2: Function with Arguments, With Return**
```cpp
#include <iostream>
using namespace std;

int multiply(int a, int b) {
    return a * b;
}

int main() {
    int result = multiply(4, 5);
    cout << "Product is: " << result << endl;  // Output: Product is: 20
    return 0;
}
```

- **Q:** When is returning a value preferable to printing directly inside the function?  
  **A:** Returning a value offers flexibility, allowing the caller to decide how to use or display the result.

**Example 3: Recursive Function (Factorial)**
```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n <= 1) return 1;  // Base case to stop recursion
    return n * factorial(n - 1);
}

int main() {
    cout << "Factorial of 5 is: " << factorial(5) << endl;  // Output: 120
    return 0;
}
```

- **Q:** What is essential in every recursive function?  
  **A:** A base case is crucial to avoid infinite recursion and stack overflow.

**Example 4: Inline Function**
```cpp
#include <iostream>
using namespace std;

inline int square(int x) {
    return x * x;
}

int main() {
    cout << "Square of 6 is: " << square(6) << endl;  // Output: 36
    return 0;
}
```

- **Q:** When should inline functions be used?  
  **A:** For short, frequently called functions where reducing call overhead is beneficial.

**Example 5: Lambda Function**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> numbers = {1, 2, 3, 4, 5};
    for_each(numbers.begin(), numbers.end(), [](int x) {
        cout << x << " ";
    });
    cout << endl;
    return 0;
}
```

- **Q:** In what scenario are lambda functions most useful?  
  **A:** When you need a quick, inline function for one-time operations like algorithm callbacks or simple data transformations.

---

## 2. Function Calls: Pass by Value vs. Pass by Reference

### **Introduction**
The way you pass parameters to functions can impact performance and behavior. C++ supports passing by value (copying the data) and by reference (providing direct access to the original data).

### **Core Concepts & Explanations**
- **Pass by Value:**  
  The function receives a copy of the variable. Changes made inside the function do not affect the original.
  
- **Pass by Reference:**  
  The function receives a reference (alias) to the original variable. Changes made inside affect the original data.

### **Code Examples & Q&A**

**Pass by Value**
```cpp
#include <iostream>
using namespace std;

void addOne(int num) {
    num += 1;
    cout << "Inside function: " << num << endl;
}

int main() {
    int number = 5;
    addOne(number);
    cout << "Outside function: " << number << endl;  // number remains 5
    return 0;
}
```

**Pass by Reference**
```cpp
#include <iostream>
using namespace std;

void addOne(int &num) {
    num += 1;
    cout << "Inside function: " << num << endl;
}

int main() {
    int number = 5;
    addOne(number);
    cout << "Outside function: " << number << endl;  // number becomes 6
    return 0;
}
```

- **Q:** What are the benefits of pass by reference?  
  **A:** It allows functions to modify the original data and avoids the overhead of copying large objects.

- **Q:** When would pass by value be more appropriate?  
  **A:** When you want to ensure that the original data remains unchanged, especially with small or primitive data types.

---

## 3. Default Function Arguments

### **Introduction**
Default arguments allow you to omit some parameters when calling a function, using predefined values instead. This leads to simpler and cleaner function calls.

### **Core Concepts & Explanations**
- Default arguments help reduce redundancy by supplying common parameter values automatically.
- They increase code readability and make the function interface easier to use.

### **Code Example & Q&A**
```cpp
#include <iostream>
using namespace std;

void greet(string name = "Student") {
    cout << "Hello, " << name << "!" << endl;
}

int main() {
    greet("Alice");  // Output: Hello, Alice!
    greet();         // Output: Hello, Student!
    return 0;
}
```

- **Q:** How do default arguments improve usability?  
  **A:** They let the caller omit common parameters, reducing code clutter and potential errors.

- **Q:** What is a potential risk of using default arguments?  
  **A:** Overuse may lead to ambiguity or unexpected behavior if the defaults do not align with all use cases.

---

## 4. Variable Scope

### **Introduction**
Variable scope defines the visibility and lifetime of a variable. Understanding scope helps avoid conflicts and unintended modifications.

### **Core Concepts & Explanations**
- **Global Variables:** Declared outside functions and accessible anywhere in the code. Use sparingly due to potential side effects.
- **Local Variables:** Declared within a function or block; accessible only within that context.
- **Parameter Scope:** Function parameters are local to the function, protecting external data from unintended changes.

### **Code Examples & Q&A**

**Global vs. Local Variables**
```cpp
#include <iostream>
using namespace std;

int globalVar = 10;  // Global variable

void display() {
    cout << "Global variable: " << globalVar << endl;
}

int main() {
    int localVar = 5;  // Local variable
    cout << "Local variable: " << localVar << endl;
    display();
    return 0;
}
```

- **Q:** What are the risks associated with global variables?  
  **A:** They can be modified from anywhere, leading to unexpected side effects and making debugging more difficult.

**Modifying a Parameter (Local Scope)**
```cpp
#include <iostream>
using namespace std;

void modify(int param) {
    param = 100;  // Only modifies the local copy
}

int main() {
    int value = 50;
    modify(value);
    cout << "Value after modify: " << value << endl;  // Output: 50
    return 0;
}
```

- **Q:** How does parameter scope help maintain data integrity?  
  **A:** Changes to parameters inside a function do not affect the original data, preventing unintended modifications.

---

## 5. Code Organization in Larger Projects

### **Introduction**
As projects scale, organizing code across multiple files is essential for maintainability and modularity. Proper organization separates interface from implementation, reduces compilation times, and enhances readability.

### **Core Concepts & Explanations**
- **Single-File Projects:**  
  Suitable for small programs or prototypes.
- **Multi-File Projects:**  
  Split code into header files (declarations) and source files (definitions) to improve modularity.

### **Project Structure Example**
```
Project/
  main.cpp
  functions.h
  functions.cpp
```

**functions.h**
```cpp
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Function declarations
void printGreeting();
int add(int a, int b);

#endif
```

**functions.cpp**
```cpp
#include "functions.h"
#include <iostream>
using namespace std;

void printGreeting() {
    cout << "Welcome to the program!" << endl;
}

int add(int a, int b) {
    return a + b;
}
```

**main.cpp**
```cpp
#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    printGreeting();
    cout << "Sum: " << add(10, 20) << endl;
    return 0;
}
```

- **Q:** What are the benefits of using header and source files?  
  **A:** They promote separation of concerns, facilitate code reuse, and speed up compilation by only rebuilding modified components.

---

## 6. Arrays

### **Introduction**
Arrays are basic data structures that store elements in contiguous memory locations. They offer fast, indexed access but have a fixed size determined at compile time.

### **Core Concepts & Explanations**
- **Declaration & Initialization:**  
  Define an array with a fixed number of elements and optionally initialize it.
- **Usage in Functions:**  
  Arrays are passed as pointers, meaning that functions can modify the original array.
- **When to Use:**  
  Use arrays when the number of elements is known and fixed (e.g., days of the week, fixed-size sensor data).

### **Code Examples & Q&A**

**Basic Array Declaration and Initialization**
```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {10, 20, 30, 40, 50};
    char letters[] = {'a', 'b', 'c', 'd'};
    cout << "First number: " << numbers[0] << endl;
    cout << "First letter: " << letters[0] << endl;
    return 0;
}
```

**Passing Arrays to a Function**
```cpp
#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    printArray(arr, 5);
    return 0;
}
```

- **Q:** Why must we pass the array size to a function?  
  **A:** Because arrays decay to pointers when passed to functions, and the size information is lost without explicitly providing it.

- **Q:** In what scenario is a static array preferred over a dynamic container?  
  **A:** When working with a fixed number of elements where dynamic resizing is not required.

---

## 7. Array Iteration Techniques

### **Introduction**
Iterating over array elements is a frequent operation. C++ provides various methods for iteration, from traditional loops to modern functional approaches.

### **Core Concepts & Explanations**
- **Traditional For Loop:**  
  Uses an index variable to access each element.
- **Range-Based For Loop (C++11):**  
  Simplifies iteration by directly using elements.
- **for_each with Lambda:**  
  Applies a lambda function to each element, merging functional programming with iteration.

### **Code Examples & Q&A**

**Traditional For Loop**
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
```

**Range-Based For Loop**
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    for (auto x : arr) {  // x is a copy by default.
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
```

*Tip:* Use a reference if you wish to modify the original elements:
```cpp
for (auto &x : arr) {
    x *= 2;
}
```

**Using for_each with Lambda**
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    for_each(arr, arr + size, [](int x) {
        cout << x << " ";
    });
    cout << endl;
    return 0;
}
```

- **Q:** What advantage does a range-based loop have over a traditional loop?  
  **A:** It reduces boilerplate code and eliminates the risk of indexing errors.

- **Q:** When might you choose `for_each` with a lambda?  
  **A:** When you want to perform inline operations on each element, keeping your code concise and expressive.

---

## 8. Vectors (std::vector)

### **Introduction**
Vectors are dynamic arrays that can resize automatically as needed. They are one of the most commonly used STL containers for managing a collection of elements.

### **Core Concepts & Explanations**
- **Dynamic Sizing:**  
  Easily add or remove elements using functions like `push_back()` and `pop_back()`.
- **Random Access:**  
  Elements can be accessed quickly using indices.
- **Utility Methods:**  
  Vectors provide a rich set of member functions to manage the data effectively.

### **Commonly Used Functions Table for std::vector**

| Function       | Description                                                          |
|----------------|----------------------------------------------------------------------|
| `push_back()`  | Adds an element to the end of the vector.                            |
| `pop_back()`   | Removes the last element.                                            |
| `size()`       | Returns the number of elements.                                      |
| `empty()`      | Checks if the vector is empty.                                       |
| `at(index)`    | Returns element at the given index with bounds checking.             |
| `front()`      | Returns the first element.                                           |
| `back()`       | Returns the last element.                                            |
| `begin()/end()`| Returns an iterator to the beginning/end of the vector.              |
| `insert()`     | Inserts element(s) at the specified position.                        |
| `erase()`      | Removes element(s) from the specified position.                      |
| `clear()`      | Removes all elements from the vector.                                |
| `resize()`     | Changes the number of elements stored in the vector.                 |
| `capacity()`   | Returns the total storage space allocated.                           |

### **Code Example & Q&A**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {1, 2, 3};
    vec.push_back(4);
    vec.push_back(5);

    // Iterating using a range-based loop
    for (int x : vec) {
        cout << x << " ";
    }
    cout << endl;

    cout << "Element at index 2: " << vec[2] << endl;  // Output: 3
    return 0;
}
```

- **Q:** Why choose vectors over static arrays?  
  **A:** Vectors provide dynamic resizing and numerous utility functions, making them flexible for changing datasets.

- **Q:** How might vectors be applied in real-world applications?  
  **A:** Vectors can store user inputs, dynamically sized datasets, or serve as buffers in real-time applications.

---

## 9. Lists (std::list)

### **Introduction**
Lists are doubly linked lists that allow efficient insertions and deletions at any position, making them ideal for scenarios where such operations are frequent.

### **Core Concepts & Explanations**
- **Doubly Linked Structure:**  
  Each element has pointers to both the previous and next elements.
- **Sequential Access:**  
  Fast insertion and deletion but no random access.
- **Usage Scenarios:**  
  Often used in task scheduling, managing playlists, or any situation with frequent mid-sequence modifications.

### **Commonly Used Functions Table for std::list**

| Function        | Description                                                    |
|-----------------|----------------------------------------------------------------|
| `push_back()`   | Adds an element to the end of the list.                        |
| `push_front()`  | Adds an element to the beginning of the list.                  |
| `pop_back()`    | Removes the last element.                                      |
| `pop_front()`   | Removes the first element.                                     |
| `size()`        | Returns the number of elements.                                |
| `empty()`       | Checks if the list is empty.                                   |
| `front()`       | Accesses the first element.                                    |
| `back()`        | Accesses the last element.                                     |
| `insert()`      | Inserts element(s) at a specified position.                    |
| `erase()`       | Removes element(s) at a specified position.                    |
| `clear()`       | Removes all elements from the list.                            |
| `sort()`        | Sorts the list elements.                                       |
| `reverse()`     | Reverses the order of elements.                                |

### **Code Example & Q&A**
```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> myList = {10, 20, 30};
    myList.push_back(40);

    // Iterating through the list
    for (int x : myList) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
```

- **Q:** Why might a list be preferred over a vector?  
  **A:** Lists are more efficient for frequent insertions and deletions, especially in the middle of the collection.

- **Q:** What is the main drawback of using a list?  
  **A:** They do not support fast random access.

---

## 10. Stack (std::stack)

### **Introduction**
A stack is a container adapter that follows the Last In, First Out (LIFO) principle. It is especially useful in scenarios like undo operations, expression evaluation, and backtracking algorithms.

### **Core Concepts & Explanations**
- **LIFO Behavior:**  
  Only the most recently added element (the top) is accessible.
- **Underlying Containers:**  
  Typically built on top of `deque` or `vector`.

### **Commonly Used Functions Table for std::stack**

| Function    | Description                                         |
|-------------|-----------------------------------------------------|
| `push()`    | Adds an element to the top of the stack.          |
| `pop()`     | Removes the top element from the stack.           |
| `top()`     | Returns the top element.                            |
| `empty()`   | Checks if the stack is empty.                     |
| `size()`    | Returns the number of elements in the stack.      |

### **Code Example & Q&A**
```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    
    while (!stk.empty()) {
        cout << "Top element: " << stk.top() << endl;
        stk.pop();
    }
    return 0;
}
```

- **Q:** What is a primary limitation of a stack?  
  **A:** You can only access the top element, which restricts the operations to LIFO behavior.

- **Q:** Provide a real-world use case for a stack.  
  **A:** Stacks are used in implementing undo features in text editors where the most recent changes are reversed first.

---

## 11. Maps (std::map)

### **Introduction**
Maps are associative containers that store elements in key-value pairs, maintaining the keys in a sorted order. They provide fast lookup, insertion, and deletion operations based on keys.

### **Core Concepts & Explanations**
- **Associative Storage:**  
  Every element is a key-value pair, ensuring that each key is unique.
- **Sorted Keys:**  
  Typically implemented as balanced binary trees (e.g., red-black trees).
- **Usage Scenarios:**  
  Ideal for tasks like building a dictionary, phone directory, or caching system.

### **Commonly Used Functions Table for std::map**

| Function         | Description                                                               |
|------------------|---------------------------------------------------------------------------|
| `operator[]`     | Accesses or inserts an element with the given key.                        |
| `at()`           | Returns the value for a given key with bounds checking.                   |
| `insert()`       | Inserts a key-value pair.                                                 |
| `erase()`        | Removes element(s) by key or iterator.                                    |
| `find()`         | Searches for an element by key.                                           |
| `count()`        | Returns the count of elements with a given key (0 or 1 for maps).           |
| `clear()`        | Removes all elements.                                                     |
| `size()`         | Returns the number of key-value pairs.                                    |
| `empty()`        | Checks if the map is empty.                                               |
| `lower_bound()`  | Returns an iterator to the first element not less than the specified key. |
| `upper_bound()`  | Returns an iterator to the first element greater than the specified key.  |

### **Code Example & Q&A**
```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> ageMap;
    ageMap["Alice"] = 25;
    ageMap["Bob"] = 30;
    ageMap["Charlie"] = 22;
    
    for (const auto &entry : ageMap) {
        cout << entry.first << " is " << entry.second << " years old." << endl;
    }
    return 0;
}
```

- **Q:** How does a map maintain its order?  
  **A:** By using a balanced binary tree, ensuring the keys remain sorted.
  
- **Q:** What is a practical application of maps?  
  **A:** They can be used to implement a phone directory or store configuration settings for quick lookup.

---

## 12. Strings (std::string)

### **Introduction**
The `std::string` class provides a flexible and efficient way to work with sequences of characters. Unlike C-style strings, `std::string` handles memory management automatically and comes with a variety of built-in functions.

### **Core Concepts & Explanations**
- **Dynamic Nature:**  
  Strings can grow or shrink as needed.
- **Rich Functionality:**  
  Provides a host of member functions for manipulation, comparison, and searching.
- **Usage Scenarios:**  
  Widely used for processing user input, text manipulation, file handling, and more.

### **Commonly Used Functions Table for std::string**

| Function              | Description                                                       |
|-----------------------|-------------------------------------------------------------------|
| `length()` / `size()` | Returns the number of characters in the string.                   |
| `empty()`             | Checks if the string is empty.                                     |
| `append()`            | Appends additional characters or another string.                   |
| `operator+`           | Concatenates two strings.                                          |
| `operator+=`          | Appends a string or character to the existing string.              |
| `substr()`            | Returns a substring from a specified position.                     |
| `find()`              | Searches for a substring within the string.                        |
| `compare()`           | Compares two strings lexicographically.                            |
| `c_str()`             | Returns a pointer to a C-style null-terminated string.               |
| `clear()`             | Removes all characters from the string.                            |
| `push_back()`         | Adds a character to the end of the string.                         |
| `insert()`            | Inserts characters at a specified position.                        |
| `erase()`             | Erases characters from the string.                                 |
| `replace()`           | Replaces a portion of the string with another string.              |
| `begin()` / `end()`    | Returns iterators to the beginning/end of the string.              |

### **Code Example & Q&A**
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string greeting = "Hello";
    greeting += ", World!";
    
    cout << "Greeting: " << greeting << endl;
    cout << "Length: " << greeting.size() << endl;
    
    string sub = greeting.substr(7, 5);  // Extracts "World"
    cout << "Substring: " << sub << endl;
    
    // Finding a substring
    size_t pos = greeting.find("World");
    if (pos != string::npos) {
        cout << "\"World\" found at position: " << pos << endl;
    }
    
    return 0;
}
```

- **Q:** What advantages does `std::string` have over C-style strings?  
  **A:** `std::string` automatically manages memory, offers rich functionality, and is much safer and easier to use.

- **Q:** How can strings be used in real-world applications?  
  **A:** They are used in parsing user input, constructing dynamic messages, handling file contents, and any scenario involving text processing.

---

# Conclusion

This Unit-01 guide provides an in-depth look into the basics of C++ programming and its standard data structures. We explored:

- **Functions:** Various types, recursion, inlining, and lambdas.  
- **Function Calls:** Differences between pass by value and pass by reference.  
- **Default Arguments & Variable Scope:** Simplifying function calls and managing data access.  
- **Code Organization:** Structuring multi-file projects for scalability.
- **Arrays & Iteration Techniques:** Working with fixed-size collections and various iteration methods.
- **STL Data Structures:** Detailed explanations and tables for vectors, lists, stacks, maps, and strings, including practical examples and comprehensive function summaries.