#include <iostream>
#include <algorithm> // for std::is_sorted
#include <queue>     // for std::priority_queue

void heapSort(int arr[], int n)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    for (int i = 0; i < n; i++)
        minHeap.push(arr[i]);

    for (int i = 0; i < n; i++)
    {
        arr[i] = minHeap.top();
        minHeap.pop();
    }
};

void printArray(int arr[], int n)
{
    std::cout << "[";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i];
        if (i < n - 1)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}

void testHeapSort()
{
    // Test 1: Empty array
    int test1[] = {};
    std::cout << "Test 1: ";
    printArray(test1, 0);
    heapSort(test1, 0);
    printArray(test1, 0);
    if (std::is_sorted(test1, test1))
        std::cout << "Test 1 passed.\n\n";
    else
        std::cout << "Test 1 failed.\n\n";

    // Test 2: Array with one element
    int test2[] = {1};
    std::cout << "Test 2: ";
    printArray(test2, 1);
    heapSort(test2, 1);
    printArray(test2, 1);
    if (std::is_sorted(test2, test2 + 1))
        std::cout << "Test 2 passed.\n\n";
    else
        std::cout << "Test 2 failed.\n\n";

    // Test 3: Array with two elements
    int test3[] = {2, 1};
    std::cout << "Test 3: ";
    printArray(test3, 2);
    heapSort(test3, 2);
    printArray(test3, 2);
    if (std::is_sorted(test3, test3 + 2))
        std::cout << "Test 3 passed.\n\n";
    else
        std::cout << "Test 3 failed.\n\n";

    // Test 4: Array with multiple elements
    int test4[] = {4, 3, 2, 1};
    std::cout << "Test 4: ";
    printArray(test4, 4);
    heapSort(test4, 4);
    printArray(test4, 4);
    if (std::is_sorted(test4, test4 + 4))
        std::cout << "Test 4 passed.\n\n";
    else
        std::cout << "Test 4 failed.\n\n";

    // Test 5: Array with duplicate elements
    int test5[] = {2, 1, 2, 1};
    std::cout << "Test 5: ";
    printArray(test5, 4);
    heapSort(test5, 4);
    printArray(test5, 4);
    if (std::is_sorted(test5, test5 + 4))
        std::cout << "Test 5 passed.\n\n";
    else
        std::cout << "Test 5 failed.\n\n";
}

int main()
{
    testHeapSort();
    return 0;
}
