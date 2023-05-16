#include <iostream>
#include <vector>

void swap(std::vector<int> &arr, int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];  
    int i = (low - 1);  
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;  
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return (i + 1);
}

void quickSortRec(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quickSortRec(arr, low, pivot - 1);
        quickSortRec(arr, pivot + 1, high);
    }
}

void quickSort(std::vector<int> &arr)
{
    quickSortRec(arr, 0, arr.size() - 1);
}

void printArray(const std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    std::cout << "Unsorted array is: ";
    printArray(arr);

    quickSort(arr);

    std::cout << "Sorted array is: ";
    printArray(arr);

    return 0;
}
