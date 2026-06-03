#include <iostream>

using namespace std;

/**
 * @brief Node for singly linked list
 */
struct Node {
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int value) : data(value), next(nullptr) {}
};


/**
 * @brief Singly Linked List
 */
struct LinkedList {
    Node* head;
    Node* tail;

    LinkedList() : head(nullptr), tail(nullptr) {}

    LinkedList(int value) {
        head = new Node(value);
        tail = head;
    }

    /**
     * @brief Destructor
     *
     * Responsible for freeing all dynamically allocated memory.
     *
     * After execution:
     * - No memory leaks should exist
     * - head and tail should both be nullptr
     *
     * Can you implement this?
     *
     * Hints:
     * - Traverse the list using a loop
     * - Store next node before deleting current node
     * - Delete nodes one by one
     * - Reset head and tail at the end
     */
    ~LinkedList() {
        // TODO: Implement
    }

    /**
     * @brief Insert at tail (O(1))
     */
    void insert(int value) {
        Node* newNode = new Node(value);

        if (!head) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    /**
     * @brief Find if a key exists in the list
     *
     * @param key value to search for
     * @return true if found, false otherwise
     *
     * Can you implement this?
     *
     * Hints:
     * - Traverse from head to nullptr
     * - Compare each node's data with key
     * - Return early if found
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
     * Input:  [10 -> 20 -> 10 -> 30 -> 10], key = 10
     * Output: 3
     */
        int count_key(int key) const {
            // TODO: Implement
            return 0;
        }

    /**
     * @brief Remove ALL occurrences of key (implemented)
     */
    bool remove(int key) {
        bool removed = false;

        while (head && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            removed = true;
        }

        if (!head) {
            tail = nullptr;
            return removed;
        }

        Node* curr = head;

        while (curr->next) {
            if (curr->next->data == key) {
                Node* temp = curr->next;
                curr->next = temp->next;

                if (temp == tail)
                    tail = curr;

                delete temp;
                removed = true;
            } else {
                curr = curr->next;
            }
        }

        return removed;
    }

    /**
     * @brief Remove all occurrences of key and return count
     *
     * @param key value to remove
     * @return number of nodes removed
     *
     * Can you implement this?
     *
     * Hints:
     * - Similar to remove(), but count how many nodes are deleted
     * - Maintain an integer counter
     * - Handle:
     *   - multiple removals at head
     *   - removal in middle
     *   - tail updates when last node is deleted
     */
    int remove_count(int key) {
        // TODO: Implement
        return 0;
    }

    /**
     * @brief Replace the first n occurrences of old_key with new_key
     *
     * @param old_key value to replace
     * @param new_key value to replace with
     * @param n number of replacements required
     * @return true if exactly n replacements made, false otherwise
     *
     * Behavior:
     * - If fewer than n occurrences exist, replace as many as possible and return false
     *
     * Can you implement this?
     *
     * Hints:
     * - Traverse from head
     * - Maintain a counter for replacements
     * - Replace node->data when match is found
     * - Stop once n replacements are done
     */
    bool replace_n(int old_key, int new_key, int n) {
        // TODO: Implement
        return false;
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
};


/**
 * @brief Driver code
 */
int main() {
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(10);
    list.insert(30);
    list.insert(10);

    cout << "Initial List: ";
    list.print();

    cout << "\nFind 20: " << list.find(20) << endl;
    cout << "Find 99: " << list.find(99) << endl;

    cout << "\nReplace first 2 occurrences of 10 with 99\n";
    list.replace_n(10, 99, 2);
    list.print();

    cout << "\nRemove all 10 and count\n";
    cout << "Removed count: " << list.remove_count(10) << endl;
    list.print();

    return 0;
}