#include <iostream>
#include <cstdlib> // for rand()

void insertionSort(int arr[], int n);

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

        insertionSort(arr, n);

        std::cout << "\nSorted array (size " << n << "): ";
        for (int j = 0; j < n; j++)
        {
            std::cout << arr[j] << " ";
        }
        std::cout << "\n\n";
    }

    return 0;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            // Swap
            int aux = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = aux;
            j--;
        }
    }
}

