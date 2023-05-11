#include <iostream>
#include <algorithm> // for std::is_sorted

#include <vector>
#include <string>

int getDigitOfInt(int index, int number)
{
    int divisor = 1;
    for (int i = 0; i < index; i++)
        divisor *= 10;
    int digit = (number / divisor) % 10;
    return digit;
}

void radixSort(int arr[], int n)
{
    int maxVal = *std::max_element(arr, arr + n); // This needs to iterate the array so O(n)
    std::vector<std::vector<int>> buckets(10);

    for (int i = 0; i < maxVal; i++) // Runs d times , d = maxVal (max num of digits)
    {
        for (int j = 0; j < n; j++) // n times
        {
            int bucketIndex = getDigitOfInt(i, arr[j]); // This also has a foor loop that executes i times, i is actually d at most.
            buckets[bucketIndex].push_back(arr[j]);
        }

        int k = 0;
        for (std::vector<int> &bucket : buckets) // The code inside will be executed b times so  +b
        {
            for (int value : bucket) // The code inside will be executed n times so => +n
            {
                arr[k] = value;
                k++;
            }
            bucket.clear(); // You will need to move memory around worst case n times.
        }
    }
    // d => maxElement
    // b => numOfBuckets
    // So taking all costs into account actually this radix sort is => O(n + d*( (n + d) + (b*n + n)))
    // O(n + d*2*n + d^2 + dbn) => d and b can be considered usually really small and not growing with
    // the arr[] size so we can ignore them considreing constant time getting
    // => O(n + 1*2*n + 1 + 1*1*n) => O(4n) => So overall O(n)
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

void testRadixSort()
{
    // Test 1: Empty array
    int test1[] = {};
    std::cout << "Test 1: ";
    printArray(test1, 0);
    radixSort(test1, 0);
    printArray(test1, 0);
    if (std::is_sorted(test1, test1))
        std::cout << "Test 1 passed.\n\n";
    else
        std::cout << "Test 1 failed.\n\n";

    // Test 2: Array with one element
    int test2[] = {1};
    std::cout << "Test 2: ";
    printArray(test2, 1);
    radixSort(test2, 1);
    printArray(test2, 1);
    if (std::is_sorted(test2, test2 + 1))
        std::cout << "Test 2 passed.\n\n";
    else
        std::cout << "Test 2 failed.\n\n";

    // Test 3: Array with two elements
    int test3[] = {2, 1};
    std::cout << "Test 3: ";
    printArray(test3, 2);
    radixSort(test3, 2);
    printArray(test3, 2);
    if (std::is_sorted(test3, test3 + 2))
        std::cout << "Test 3 passed.\n\n";
    else
        std::cout << "Test 3 failed.\n\n";

    // Test 4: Array with multiple elements
    int test4[] = {4, 3, 2, 1};
    std::cout << "Test 4: ";
    printArray(test4, 4);
    radixSort(test4, 4);
    printArray(test4, 4);
    if (std::is_sorted(test4, test4 + 4))
        std::cout << "Test 4 passed.\n\n";
    else
        std::cout << "Test 4 failed.\n\n";

    // Test 5: Array with duplicate elements
    int test5[] = {2, 1, 2, 1};
    std::cout << "Test 5: ";
    printArray(test5, 4);
    radixSort(test5, 4);
    printArray(test5, 4);
    if (std::is_sorted(test5, test5 + 4))
        std::cout << "Test 5 passed.\n\n";
    else
        std::cout << "Test 5 failed.\n\n";
}

int main()
{
    testRadixSort();
    return 0;
}
