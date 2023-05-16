#include <iostream>

void selectionSort(int arr[], int n);

int main()
{
    int arr[] = {5, 2, 7, 3, 6, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    selectionSort(arr, n);

    std::cout << "\nAfter sorting: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}

void selectionSort(int arr[], int n)
{
    int lastSortedIndex = 0;
    while (lastSortedIndex < n)
    {
        int indexOfMin = lastSortedIndex;
        int minValue = arr[lastSortedIndex];
        // Check for the smallest element.
        for (int i = lastSortedIndex; i < n; i++)
        {
            if (arr[i] < minValue)
            {
                minValue = arr[i];
                indexOfMin = i;
            }
        }
        // Exchange positions to the leftest index.
        int aux = arr[lastSortedIndex];
        arr[lastSortedIndex] = minValue;
        arr[indexOfMin] = aux;
        lastSortedIndex++;
    }
}
