#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;
/*
------------------------------------------------------------
SIMPLE APPROACH (rand()) - EASY BUT LIMITED

int getRandomNumber(const int& min, const int& max) {
    return min + rand() % (max - min + 1);
}

Why it's simple:
- Very easy to understand
- Requires only rand() and srand()
- Common in beginner examples

Limitations:
- Not truly uniform (modulo bias)
- Low-quality randomness
- Small range (depends on RAND_MAX)
- Predictable sequence (not good for serious use)
------------------------------------------------------------
*/

// BETTER APPROACH (C++ <random>)
int getRandomNumber(const int& min, const int& max) {
    static random_device rd;              // seed source
    static mt19937 gen(rd());             // high-quality generator
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

/*
Why use this approach:
- Produces high-quality random numbers
- Uniform distribution (no bias)
- Large internal state → less predictable
- Industry standard in modern C++
- Easy to extend (normal distribution, etc.)
*/


// Function to generate array using the RNG
vector<int> generateRandomArray(int nitems, int min, int max) {
    vector<int> arr;
    for (int i = 0; i < nitems; i++) {
        arr.push_back(getRandomNumber(min, max));
    }
    return arr;
}


// Binary Search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;

        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}


int main() {
    vector<int> arr = generateRandomArray(10, 1, 100);
    cout << "Array (Random Order): ";
    for (int x : arr) cout << x << " ";

    sort(arr.begin(), arr.end());
    cout << "\nArray (Sorted): ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int target = arr[4];

    cout << "Searching for: " << target << endl;

    int index = binarySearch(arr, target);

    if (index != -1)
        cout << "Found at index: " << index << endl;
    else
        cout << "Not found" << endl;

    return 0;
}