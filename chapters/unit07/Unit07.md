# Unit-07: Templates

Welcome to Unit-07! In this unit, we explore C++ templates—a cornerstone of generic programming. Templates empower you to write code that works with any data type, promoting reusability and type safety. This unit covers template functions, template specialization, non-type template parameters, and variadic templates. Throughout, you'll find detailed explanations, illustrative code examples, and plenty of tricky questions (with answers) to challenge your understanding.

---

## 1. Template Functions

### Overview & Concepts
Template functions allow you to write a single function definition that works with multiple data types. Instead of writing overloaded functions for each type, you define a template that the compiler instantiates with the appropriate type based on the arguments.

- **Syntax:**  
  ```cpp
  template <typename T>
  T myMax(T x, T y) {
      return (x > y) ? x : y;
  }
  ```
- **Type Deduction:**  
  In many cases, the compiler deduces the type automatically (e.g., `myMax('a', 'z')` deduces `T` as `char`).

### Code Example: Template Function
```cpp
#include <iostream>
using namespace std;

template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}

int main() {
    cout << "Max of 10 and 20: " << myMax(10, 20) << endl;           // int
    cout << "Max of 3.14 and 2.71: " << myMax(3.14, 2.71) << endl;     // double
    cout << "Max of 'g' and 'e': " << myMax('g', 'e') << endl;         // char
    return 0;
}
```

### Tricky Questions
1. **Q:** How does the compiler determine the type for a template function when you call `myMax(5, 7)`?  
   **A:** The compiler deduces the type `T` as `int` based on the types of the arguments provided.

2. **Q:** Can you explicitly specify the type when calling a template function? Provide an example.  
   **A:** Yes, for example: `myMax<double>(5, 7)` forces the compiler to treat the arguments as `double`.

3. **Q:** What happens if you call `myMax(3, 4.5)`?  
   **A:** The compiler will attempt to deduce a common type. Since there is no implicit conversion that makes both parameters the same type without ambiguity, it might result in a compilation error or require an explicit cast.

---

## 2. Template Specialization

### Overview & Concepts
Template specialization lets you provide a custom implementation of a template for a specific data type. This is useful when the generic implementation is not optimal or when you want to add special behavior.

### Code Example: Template Specialization
```cpp
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}

// Specialization for C-style strings
template <>
const char* myMax<const char*>(const char* x, const char* y) {
    return (strcmp(x, y) > 0) ? x : y;
}

int main() {
    cout << "Max of 10 and 20: " << myMax(10, 20) << endl;  
    cout << "Max of \"apple\" and \"orange\": " << myMax("apple", "orange") << endl;
    return 0;
}
```

### Tricky Questions
4. **Q:** Why might you need to specialize a template function for C-style strings?  
   **A:** Because the default implementation would compare pointer addresses rather than the actual string contents.

5. **Q:** What would happen if you forgot to specialize a template for a type that requires special treatment?  
   **A:** The generic template would be used, which could lead to incorrect behavior or runtime errors.

6. **Q:** How do you declare a full specialization of a template function?  
   **A:** By providing the template keyword with an empty parameter list, as shown in the example with `template <>`.

---

## 3. Non-Type Template Parameters

### Overview & Concepts
Non-type template parameters allow you to pass values (not just types) to templates. This feature increases flexibility and enables behavior based on compile-time constants.

- **Examples of Non-Type Parameters:** Integral values, pointers, references, or `constexpr` objects.

### Code Example: Non-Type Template Parameter
```cpp
#include <iostream>
using namespace std;

template <typename T, int size>
void printArray(T (&arr)[size]) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    printArray(numbers);  // Compiler deduces size = 5
    return 0;
}
```

### Tricky Questions
7. **Q:** What is a non-type template parameter?  
   **A:** It is a template parameter that represents a value (e.g., an integer) rather than a type.

8. **Q:** How does the compiler determine the non-type template parameter in the `printArray` example?  
   **A:** It deduces the size of the array from the function argument, allowing the template to work with any fixed-size array.

9. **Q:** What limitations exist on non-type template parameters?  
   **A:** They must be constant expressions, and typically can only be of integral or pointer types.

---

## 4. Variadic Templates

### Overview & Concepts
Variadic templates allow functions (or classes) to accept an arbitrary number of template parameters. They are essential for creating flexible and generic code that can handle a varying number of arguments.

### Code Example: Variadic Template Function
```cpp
#include <iostream>
using namespace std;

// Base case: no arguments
void print() {
    cout << endl;
}

// Variadic template function
template <typename T, typename... Args>
void print(T first, Args... args) {
    cout << first << " ";
    print(args...);  // Recursive call with remaining arguments
}

int main() {
    print(1, 2.5, "hello", 'A');
    return 0;
}
```

### Tricky Questions
10. **Q:** What is the purpose of the base case in a variadic template function?  
    **A:** The base case stops the recursion, preventing infinite template instantiation.

11. **Q:** How are variadic templates implemented in the example above?  
    **A:** By using recursion: the function prints the first argument and then calls itself with the remaining arguments.

12. **Q:** What does the syntax `Args... args` represent in the template function?  
    **A:** It represents a parameter pack, which can hold an arbitrary number of arguments.

13. **Q:** Can variadic templates be used with classes as well as functions?  
    **A:** Yes, variadic templates can be applied to both class templates and function templates.

---

## 5. Best Practices and Common Pitfalls

### Best Practices
- **Keep It Simple:** Write templates that are easy to read and understand.
- **Use Type Deduction:** Let the compiler deduce types when possible.
- **Specialize Only When Necessary:** Use specialization for types that require distinct behavior.
- **Document Your Code:** Clearly comment on your template parameters and the intended use.

### Common Pitfalls
- **Over-Complexity:** Excessive use of templates can lead to code that is hard to read and debug.
- **Compilation Errors:** Template errors can be cryptic; try to simplify and isolate issues.
- **Ambiguous Deductions:** Ensure that your templates can correctly deduce the types and values needed.

### Tricky Questions
14. **Q:** What are some common pitfalls when writing template code in C++?  
    **A:** Common pitfalls include overly complex code, ambiguous type deductions, and cryptic compiler errors.

15. **Q:** How can you improve the readability of template code?  
    **A:** By breaking complex templates into simpler components, using type aliases, and providing clear documentation.

16. **Q:** When should you consider using template specialization?  
    **A:** When the general template does not perform optimally or correctly for a specific type, or when you want to add specialized behavior.

17. **Q:** What is one advantage of using templates for generic programming?  
    **A:** They enable code reuse and type safety without sacrificing performance, as code is generated at compile time.

---

## 6. Conclusion

This Unit-07 guide has explored the powerful world of C++ templates:
- **Template Functions:** Write generic functions that work with any data type.
- **Template Specialization:** Customize behavior for specific types.
- **Non-Type Template Parameters:** Pass compile-time constants to templates.
- **Variadic Templates:** Handle functions or classes with an arbitrary number of parameters.
- **Best Practices:** Maintain clarity and simplicity in your template code.