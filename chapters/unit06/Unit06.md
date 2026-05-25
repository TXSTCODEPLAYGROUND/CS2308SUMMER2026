# Unit-06: Abstract Data Structures

Welcome to Unit-06! In this unit, we explore the theoretical foundations and practical implementations of abstract data structures (ADS). Abstract data structures define *what* operations are available and their behavior, without specifying the details of how these operations are implemented. Understanding ADS is crucial for designing efficient algorithms and managing data effectively. This unit covers a variety of data structures—from basic arrays to linked lists, stacks, queues, trees, graphs, hash tables, and heaps—along with code examples, practical use cases, and plenty of tricky questions to deepen your understanding.

---

## 1. Introduction to Abstract Data Structures

### Overview & Concepts
An **Abstract Data Structure (ADS)** is a conceptual model that defines the logical behavior of data storage and manipulation. It specifies:
- **What data is stored**
- **Which operations can be performed on the data**
- **The expected behavior (e.g., order, access time) of these operations**

Abstract data structures hide implementation details, allowing algorithms to be designed based on what operations are available rather than how they are executed.

### Tricky Questions
1. **Q:** What distinguishes an abstract data structure from its concrete implementation?  
   **A:** An ADS specifies the operations and behavior without detailing the underlying implementation, which can vary (e.g., arrays vs. linked lists for lists).

2. **Q:** Why is it important to study abstract data structures?  
   **A:** They form the foundation for designing efficient algorithms and help in selecting the right data structure for a specific problem.

---

## 2. Arrays

### Overview & Concepts
- **Definition:** An array is a collection of elements stored contiguously in memory, accessible by indices.
- **Advantages:** Fast access to elements (O(1) time) via indices.
- **Disadvantages:** Fixed size; inefficient for insertions and deletions as elements may need to be shifted.
- **Use Cases:** Static collections like fixed-size buffers, lookup tables, or representing matrices.

### Tricky Questions
3. **Q:** What is the time complexity for accessing an element in an array?  
   **A:** O(1) due to direct index-based access.

4. **Q:** Why might arrays be inefficient for insertion operations?  
   **A:** Insertion may require shifting many elements, resulting in O(n) time complexity.

---

## 3. Linked Lists

### Overview & Concepts
A **linked list** is a collection of nodes, where each node contains data and a pointer (or reference) to the next node. They allow dynamic memory allocation and efficient insertions/deletions.

### 3.1 Singly Linked Lists
- **Definition:** Each node contains data and a pointer to the next node. The last node points to `nullptr`.
- **Use Cases:** Implementing stacks and queues, or scenarios requiring frequent insertions and deletions.

#### Code Example: Singly Linked List (Insert & Delete)
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Insert at the end
void insert(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        return;
    }
    Node* curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNode;
}

// Delete first occurrence of value
void deleteNode(Node*& head, int value) {
    if (!head) return;
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* curr = head;
    while (curr->next && curr->next->data != value) {
        curr = curr->next;
    }
    if (curr->next) {
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    deleteNode(head, 20);
    // Print list
    for (Node* curr = head; curr != nullptr; curr = curr->next)
        cout << curr->data << " ";
    cout << endl;
    return 0;
}
```

### 3.2 Doubly Linked Lists
- **Definition:** Each node contains pointers to both the next and previous nodes, enabling bidirectional traversal.
- **Use Cases:** Navigation systems (e.g., web browser history), deques, or any application needing efficient backward and forward traversals.

#### Tricky Questions
5. **Q:** What is the primary advantage of a doubly linked list over a singly linked list?  
   **A:** It allows traversal in both directions, which simplifies operations like deletion when only a reference to the node is given.

6. **Q:** What additional memory overhead does a doubly linked list have compared to a singly linked list?  
   **A:** Each node stores an extra pointer (to the previous node), increasing memory usage.

### 3.3 Circular Linked Lists
- **Definition:** A linked list where the last node points back to the first node, forming a circle.
- **Use Cases:** Round-robin scheduling, cyclic playlists, or buffering where a continuous loop is desired.

#### Tricky Questions
7. **Q:** How do you detect a cycle in a linked list?  
   **A:** By using Floyd’s Cycle-Finding Algorithm (the tortoise and hare method).

---

## 4. Stacks and Queues

### 4.1 Stacks
- **Definition:** A collection that follows Last In, First Out (LIFO) order.
- **Use Cases:** Expression evaluation, function call management, undo operations.
- **Implementation:** Can be implemented using arrays or linked lists.

#### Code Example: Stack Using Linked List
```cpp
#include <iostream>
using namespace std;

struct StackNode {
    int data;
    StackNode* next;
    StackNode(int d) : data(d), next(nullptr) {}
};

class Stack {
private:
    StackNode* top;
public:
    Stack() : top(nullptr) {}
    
    void push(int value) {
        StackNode* newNode = new StackNode(value);
        newNode->next = top;
        top = newNode;
    }
    
    int pop() {
        if (!top) {
            throw "Stack Underflow";
        }
        int value = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        return value;
    }
    
    bool isEmpty() const {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    return 0;
}
```

#### Tricky Questions
8. **Q:** What is the time complexity for push and pop operations in a stack implemented with a linked list?  
   **A:** O(1) for both operations.

9. **Q:** Why is a stack considered a LIFO structure?  
   **A:** Because the most recently added element is the first one to be removed.

### 4.2 Queues
- **Definition:** A collection that follows First In, First Out (FIFO) order.
- **Use Cases:** Task scheduling, buffering, and handling requests in order.
- **Implementation:** Can be implemented using arrays, linked lists, or circular buffers.

#### Tricky Questions
10. **Q:** What is the key difference between a queue and a stack in terms of order?  
    **A:** A queue processes elements in FIFO order, while a stack uses LIFO order.

11. **Q:** How can a circular queue help in efficiently utilizing memory?  
    **A:** It allows for reuse of spaces freed from the front when elements are dequeued, avoiding wasted space.

---

## 5. Trees and Graphs

### 5.1 Trees
- **Definition:** A hierarchical data structure with nodes connected in a parent-child relationship.
- **Types:** Binary Trees, Binary Search Trees (BST), AVL Trees, etc.
- **Use Cases:** Databases, file systems, parsing expressions, and efficient searching/sorting.

#### Tricky Questions
12. **Q:** What is the height of a balanced binary tree with n nodes?  
    **A:** O(log n), since the tree is balanced.

13. **Q:** Why are binary search trees useful for searching?  
    **A:** They allow for efficient search operations (average-case O(log n)) by maintaining sorted order.

### 5.2 Graphs
- **Definition:** A collection of nodes (vertices) connected by edges.
- **Use Cases:** Social networks, transportation grids, dependency graphs, and network routing.
- **Properties:** Can be directed or undirected, weighted or unweighted.

#### Tricky Questions
14. **Q:** What is the difference between a tree and a graph?  
    **A:** A tree is a connected graph with no cycles, while a graph may contain cycles and disconnected components.

15. **Q:** Which algorithm is commonly used to find the shortest path in a weighted graph?  
    **A:** Dijkstra's algorithm.

---

## 6. Hash Tables

### Overview & Concepts
- **Definition:** A data structure that implements an associative array, mapping keys to values using a hash function.
- **Advantages:** Provides average-case O(1) lookup, insertion, and deletion.
- **Collision Handling:** Techniques such as chaining or open addressing are used to manage collisions.

#### Tricky Questions
16. **Q:** What is the main advantage of using a hash table?  
    **A:** Fast average-case performance for lookup, insertion, and deletion.

17. **Q:** How do hash tables handle collisions?  
    **A:** By using methods like chaining (storing collided items in a list) or open addressing (finding another slot).

---

## 7. Heaps

### Overview & Concepts
- **Definition:** A specialized tree-based data structure that satisfies the heap property:
  - **Max Heap:** Parent nodes are greater than or equal to their children.
  - **Min Heap:** Parent nodes are less than or equal to their children.
- **Use Cases:** Implementing priority queues, heapsort, and algorithms like Dijkstra's.

#### Tricky Questions
18. **Q:** What is the time complexity of inserting an element into a heap?  
    **A:** O(log n), as the element may need to percolate up the tree.

19. **Q:** How does heapsort utilize a heap to sort an array?  
    **A:** It builds a heap from the array, then repeatedly removes the root (largest or smallest element) and rebuilds the heap, resulting in O(n log n) time.

---

## 8. Fun Exercise: Simulating a Function Call Stack

### Overview & Concepts
Simulate the function call stack using a stack data structure to visualize how recursive calls are managed.

**Steps:**
1. **Define a Stack Node:** Each node represents a function call with its name and parameters.
2. **Implement the Call Stack Class:** Include methods to push (simulate a call) and pop (simulate a return).
3. **Demonstrate with a Recursive Function:** For example, simulate the recursive calls in a factorial function.

#### Pseudocode Example
```cpp
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct CallFrame {
    string functionName;
    int parameter;
    // You can add local variables if needed.
};

void simulateFactorial(int n) {
    stack<CallFrame> callStack;
    // Simulate function calls
    while (n > 1) {
        callStack.push({"factorial", n});
        n--;  // Simulate recursive call with n-1
    }
    // Simulate unwinding the call stack
    while (!callStack.empty()) {
        CallFrame cf = callStack.top();
        cout << "Returning from " << cf.functionName << " with parameter " << cf.parameter << endl;
        callStack.pop();
    }
}

int main() {
    simulateFactorial(5);
    return 0;
}
```

#### Tricky Questions
20. **Q:** What property of a stack makes it ideal for simulating a function call stack?  
    **A:** The LIFO (Last In, First Out) property, which mirrors how function calls are handled in programming languages.

21. **Q:** In a recursive function, what does each push onto the call stack represent?  
    **A:** It represents a new function call with its own set of parameters and local variables.

22. **Q:** How does unwinding the call stack simulate returning from recursive calls?  
    **A:** By popping the last call frame, which corresponds to the most recent function call, thus simulating a return.

---

## 9. Conclusion

This Unit-06 guide has explored the rich landscape of abstract data structures, including:
- **Abstract Data Structure Basics:** Understanding the theoretical model behind data organization.
- **Arrays:** Fast indexed access with limitations on dynamic operations.
- **Linked Lists:** Variants like singly, doubly, and circular linked lists with efficient insertions and deletions.
- **Stacks and Queues:** LIFO and FIFO structures for managing ordered data.
- **Trees and Graphs:** Hierarchical and network structures for efficient searching and modeling relationships.
- **Hash Tables:** Associative arrays offering fast lookups.
- **Heaps:** Specialized trees for priority management.
- **Fun Exercise:** Simulating a function call stack to visualize recursion.