#include <iostream>

using namespace std;

/**
 * @brief Node for a doubly linked list
 *
 * Each node stores:
 * - data: integer value
 * - next: pointer to next node
 * - prev: pointer to previous node
 */
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};


/**
 * @brief Doubly Linked List
 *
 * Maintains:
 * - head: first node
 * - tail: last node
 */
struct DoublyLinkedList {
    Node* head;
    Node* tail;

    /**
     * @brief Default constructor
     */
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    /**
     * @brief Constructor with one initial node
     *
     * @param value initial value to insert
     */
    DoublyLinkedList(int value) {
        head = new Node(value);
        tail = head;
    }

    /**
     * @brief Destructor
     *
     * Responsible for freeing all dynamically allocated memory.
     *
     * After execution:
     * - no memory leaks should remain
     * - head should become nullptr
     * - tail should become nullptr
     *
     * Can you implement this?
     *
     * Hints:
     * - Start from head
     * - Store the next node before deleting the current node
     * - Move one node at a time until nullptr
     * - Reset head and tail at the end
     */
    ~DoublyLinkedList() {
        // TODO: Implement
    }

    /**
     * @brief Insert a new value at the end of the list
     *
     * Uses tail for O(1) insertion.
     *
     * @param value value to insert
     */
    void insert(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    /**
     * @brief Find whether a key exists in the list
     *
     * @param key value to search for
     * @return true if found, false otherwise
     *
     * Can you implement this?
     *
     * Hints:
     * - Start from head
     * - Traverse forward using next
     * - Compare each node's data with key
     * - Return true immediately if found
     */
    bool find(int key) const {
        // TODO: Implement
        return false;
    }

    /**
     * @brief Counts how many times a given key appears in the linked list.
     *
     * @param key The value to count
     * @return int The number of occurrences of the key in the list
     *
     * Can you implement this?
     *
     * Hints:
     * - Start from the head node
     * - Traverse the list until you reach nullptr
     * - Maintain a counter variable initialized to 0
     * - Each time node->data == key, increment the counter
     * - Return the counter at the end
     *
     * Example:
     * Input:  [10 <-> 20 <-> 10 <-> 30 <-> 10], key = 10
     * Output: 3
     */
    int count_key(int key) const {
        // TODO: Implement
        return 0;
    }

    /**
     * @brief Remove ALL occurrences of key
     *
     * @param key value to remove
     * @return true if at least one node was removed, false otherwise
     */
    bool remove(int key) {
        bool removed = false;
        Node* curr = head;

        while (curr) {
            Node* nextNode = curr->next;

            if (curr->data == key) {
                if (curr == head && curr == tail) {
                    head = tail = nullptr;
                } else if (curr == head) {
                    head = curr->next;
                    head->prev = nullptr;
                } else if (curr == tail) {
                    tail = curr->prev;
                    tail->next = nullptr;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }

                delete curr;
                removed = true;
            }

            curr = nextNode;
        }

        return removed;
    }

    /**
     * @brief Remove all occurrences of key and return how many were removed
     *
     * @param key value to remove
     * @return number of removed nodes
     *
     * Can you implement this?
     *
     * Hints:
     * - This is similar to remove()
     * - Keep a counter variable
     * - Be careful when deleting:
     *   - the only node
     *   - the head
     *   - the tail
     *   - a middle node
     * - Save curr->next before deleting curr
     */
    int remove_count(int key) {
        // TODO: Implement
        return 0;
    }

    /**
     * @brief Replace the first n occurrences of old_key with new_key
     *
     * @param old_key value to replace
     * @param new_key replacement value
     * @param n number of replacements requested
     * @return true if exactly n replacements were made, false otherwise
     *
     * Behavior:
     * - If fewer than n occurrences exist, replace as many as possible and return false
     *
     * Can you implement this?
     *
     * Hints:
     * - Traverse from head to tail
     * - Maintain a replacement counter
     * - Whenever data matches old_key, assign new_key
     * - Stop once n replacements are made
     */
    bool replace_n(int old_key, int new_key, int n) {
        // TODO: Implement
        return false;
    }

    /**
     * @brief Remove the first n occurrences of key
     *
     * @param key value to remove
     * @param n how many matching nodes to remove
     * @return true if exactly n nodes were removed, false otherwise
     */
    bool remove_n(int key, int n) {
        if (n <= 0) {
            return false;
        }

        int removed = 0;
        Node* curr = head;

        while (curr && removed < n) {
            Node* nextNode = curr->next;

            if (curr->data == key) {
                if (curr == head && curr == tail) {
                    head = tail = nullptr;
                } else if (curr == head) {
                    head = curr->next;
                    head->prev = nullptr;
                } else if (curr == tail) {
                    tail = curr->prev;
                    tail->next = nullptr;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }

                delete curr;
                removed++;
            }

            curr = nextNode;
        }

        return removed == n;
    }

    /**
     * @brief Print the linked list in the format:
     * [data] -> [data] -> ... -> nullptr
     *
     * If the list is empty, print:
     * nullptr
     */
    void print() const {
        if (!head) {
            cout << "nullptr\n";
            return;
        }

        Node* curr = head;
        while (curr) {
            cout << "[" << curr->data << "] -> ";
            curr = curr->next;
        }
        cout << "nullptr\n";
    }

    /**
     * @brief Print the list in reverse order
     *
     * Useful for checking whether prev pointers are connected correctly.
     */
    void print_reverse() const {
        if (!tail) {
            cout << "nullptr\n";
            return;
        }

        Node* curr = tail;
        while (curr) {
            cout << "[" << curr->data << "] -> ";
            curr = curr->prev;
        }
        cout << "nullptr\n";
    }
};


int main() {
    DoublyLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(10);
    list.insert(30);
    list.insert(10);

    cout << "Initial list:\n";
    list.print();

    cout << "\nInitial list in reverse:\n";
    list.print_reverse();

    cout << "\nFind 20: " << list.find(20) << endl;
    cout << "Find 99: " << list.find(99) << endl;

    cout << "\nCount of 10: " << list.count_key(10) << endl;

    cout << "\nReplace first 2 occurrences of 10 with 99\n";
    cout << "replace_n result: " << list.replace_n(10, 99, 2) << endl;
    list.print();

    cout << "\nRemove first 1 occurrence of 99\n";
    cout << "remove_n result: " << list.remove_n(99, 1) << endl;
    list.print();

    cout << "\nRemove all 10 and return removed count\n";
    cout << "Removed count: " << list.remove_count(10) << endl;
    list.print();

    cout << "\nInsert more values\n";
    list.insert(50);
    list.insert(60);
    list.insert(50);
    list.print();

    cout << "\nRemove all 50\n";
    cout << "remove result: " << list.remove(50) << endl;
    list.print();

    cout << "\nReverse check:\n";
    list.print_reverse();

    return 0;
}