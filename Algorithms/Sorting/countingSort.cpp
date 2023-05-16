#include <iostream>
#include <vector>

// This implementation of couting sort does not follow the cumulative count approach
// which is commonly taught. Instead it just iterates through the counting array an if
// there is the x value in counting[i] it places x number of i in the final array.
// Keeping track of the las filled element in the final array with an extra variable.

// Take into account that this implementation makes counting sort not a stable sorting algorithm,
// but can be more efficient that cumulative count approach in some cases. It's always a tradeoff
// and best implementation will depend on your personal usecase.

int getMaxElement(std::vector<int> &arr)
{
    if (!arr.empty())
    {
        int max = arr[0];
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        return max;
    }
    return -1;
}

std::vector<int> countingSort(std::vector<int> &arr)
{
    int k = getMaxElement(arr);
    std::vector<int> countingArray = std::vector<int>(k + 1, 0); // O(n)

    for (int i = 0; i < arr.size(); i++) // O(n)
        countingArray[arr[i]]++;

    std::vector<int> sortedArray = std::vector<int>(arr.size());

    int lastIndexInsered = -1;
    for (int i = 0; i < countingArray.size(); i++) // O(k)
    {
        for (int j = 0; j < countingArray[i]; j++) // O(r)
        {
            sortedArray[lastIndexInsered + 1] = i;
            lastIndexInsered++;
        }
    }

    // O(2n + k*r) => O(n)
    // Worst case r = k => O(2n+k^2) but usually k is small so => O(n)
    return sortedArray;
}

void printArray(const std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    std::cout << "Unsorted array is: ";
    printArray(arr);

    std::vector<int> orderedArr = countingSort(arr);

    std::cout << "Sorted array is: ";
    printArray(orderedArr);
    return 0;
}
