#include <iostream>
#include <vector>

// TODO: Implement the partition function here

// TODO: Implement the quicksort function here

void printArray(const std::vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    std::cout << "Unsorted array is: ";
    printArray(arr);

    // TODO: Call your quicksort function here

    std::cout << "Sorted array is: ";
    printArray(arr);

    return 0;
}
