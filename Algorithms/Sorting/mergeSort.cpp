#include <iostream>
#include <cstdlib> // for rand()

void mergeSort(int arr[], int n, int start, int end);
void merge(int arr[], int start, int middle, int end);

int main()
{
    srand(time(0)); // Initialize random seed

    for (int i = 0; i < 10; i++) // Repeat 10 times
    {
        int n = rand() % 20 + 1; // Generate random size between 1 and 20
        int arr[n];              // Declare array with random size

        // Fill array with random integers between 1 and 100
        for (int j = 0; j < n; j++)
        {
            arr[j] = rand() % 100 + 1;
        }

        std::cout << "Unsorted array (size " << n << "): ";
        for (int j = 0; j < n; j++)
        {
            std::cout << arr[j] << " ";
        }

        mergeSort(arr, n, 0, n - 1);

        std::cout << "\nSorted array (size " << n << "): ";
        for (int j = 0; j < n; j++)
        {
            std::cout << arr[j] << " ";
        }
        std::cout << "\n\n";
    }

    return 0;
}

void mergeSort(int arr[], int n, int start, int end)
{
    if (end > start)
    {
        int middle = (end - start) / 2 + start;
        mergeSort(arr, n, start, middle);
        mergeSort(arr, n, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

void merge(int arr[], int start, int middle, int end)
{
    int sortedArray[end - start + 1];
    int i = start;
    int j = middle + 1;
    int k = 0;
    while (i <= middle && j <= end)
    {
        if (arr[i] < arr[j])
        {
            sortedArray[k] = arr[i];
            i++;
        }
        else
        {
            sortedArray[k] = arr[j];
            j++;
        }
        k++;
    }

    while (j <= end)
    {
        sortedArray[k] = arr[j];
        j++;
        k++;
    }

    while (i <= middle)
    {
        sortedArray[k] = arr[i];
        i++;
        k++;
    }

    for (int k = 0; k < end - start + 1; k++)
        arr[k + start] = sortedArray[k];
}
