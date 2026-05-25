#include <iostream>

using namespace std;

/**
 * @brief Node for circular singly linked list
 *
 * Each node stores:
 * - data: integer value
 * - next: pointer to next node
 *
 * In a circular list:
 * - The last node points back to head (not nullptr)
 */
struct Node {
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
};


/**
 * @brief Circular Singly Linked List
 *
 * Maintains:
 * - head pointer
 * - tail pointer
 *
 * Important Property:
 * - tail->next ALWAYS points to head (if list is not empty)
 */
struct CircularLinkedList {
    Node* head;
    Node* tail;

    /**
     * @brief Default constructor
     */
    CircularLinkedList() : head(nullptr), tail(nullptr) {}

    /**
     * @brief Constructor with initial value
     *
     * Can you implement this?
     *
     * Hints:
     * - Create one node
     * - head and tail both point to it
     * - Make it circular: node->next = node
     */
    CircularLinkedList(int value) {
        // TODO: Implement
    }

    /**
     * @brief Destructor
     *
     * Responsible for freeing all nodes.
     *
     * Can you implement this?
     *
     * Hints:
     * - Circular list has no nullptr termination
     * - Use a loop that stops when you come back to head
     * - Be careful not to loop forever
     * - Special case: empty list
     */
    ~CircularLinkedList() {
        // TODO: Implement
    }

    /**
     * @brief Insert at tail
     *
     * After insertion:
     * - tail should update
     * - tail->next must still point to head
     *
     * Can you implement this?
     *
     * Hints:
     * - Handle empty list separately
     * - For non-empty:
     *   newNode->next = head
     *   tail->next = newNode
     *   update tail
     */
    void insert(int value) {
        // TODO: Implement
    }

    /**
     * @brief Find if a key exists
     *
     * @param key value to search for
     * @return true if found, false otherwise
     *
     * Can you implement this?
     *
     * Hints:
     * - Start at head
     * - Traverse using do-while loop
     * - Stop when you return to head
     */
    bool find(int key) const {
        // TODO: Implement
        return false;
    }

    /**
     * @brief Count occurrences of a key
     *
     * @param key value to count
     * @return number of occurrences
     *
     * Can you implement this?
     *
     * Hints:
     * - Use do-while traversal
     * - Handle empty list case first
     */
    int count_key(int key) const {
        // TODO: Implement
        return 0;
    }

    /**
     * @brief Remove ALL occurrences of key
     *
     * @param key value to remove
     * @return true if at least one removed
     *
     * Can you implement this?
     *
     * Hints:
     * - Must handle:
     *   - removing head
     *   - removing tail
     *   - removing middle nodes
     *   - removing the only node
     * - Carefully update tail->next when head changes
     * - Watch for infinite loops
     */
    bool remove(int key) {
        // TODO: Implement
        return false;
    }

    /**
     * @brief Remove all occurrences and return count
     *
     * @param key value to remove
     * @return number of removed nodes
     *
     * Can you implement this?
     *
     * Hints:
     * - Similar to remove()
     * - Maintain a counter
     * - Carefully track traversal boundary (head)
     */
    int remove_count(int key) {
        // TODO: Implement
        return 0;
    }

    /**
     * @brief Replace first n occurrences
     *
     * @param old_key value to replace
     * @param new_key replacement value
     * @param n number of replacements
     * @return true if exactly n replaced
     *
     * Can you implement this?
     *
     * Hints:
     * - Traverse circularly
     * - Stop after n replacements OR full cycle
     */
    bool replace_n(int old_key, int new_key, int n) {
        // TODO: Implement
        return false;
    }

    /**
     * @brief Remove first n occurrences
     *
     * @param key value to remove
     * @param n number to remove
     * @return true if exactly n removed
     *
     * Can you implement this?
     *
     * Hints:
     * - Combine logic of remove + counter
     * - Stop early when n reached
     */
    bool remove_n(int key, int n) {
        // TODO: Implement
        return false;
    }

    /**
     * @brief Print the list
     *
     * Format:
     * [data] -> [data] -> ... -> (back to head)
     *
     * If empty:
     * nullptr
     *
     * Can you implement this?
     *
     * Hints:
     * - Use do-while traversal
     * - Stop when you return to head
     * - Avoid infinite loops
     */
    void print() const {
        // TODO: Implement
    }
};


/**
 * @brief Driver code
 */
int main() {
    CircularLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    list.print();

    cout << "Find 20: " << list.find(20) << endl;
    cout << "Count 10: " << list.count_key(10) << endl;

    list.replace_n(10, 99, 1);
    list.remove_n(20, 1);

    list.print();

    cout << "Removed count: " << list.remove_count(99) << endl;

    list.print();

    return 0;
}