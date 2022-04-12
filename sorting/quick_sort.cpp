#include <cstdlib>
#include <iostream>

namespace sorting
{
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high]; // taking the last element as piovot
        int i = (low - 1);
        for (int j = low; j < high; j++)
        {
            // if current element is smaller than or equal to pivot
            if (arr[j] <= pivot)
            {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return (i + 1);
    }
    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }
    using sorting::quickSort;
    void show(int arr[], int size)
    {
        for (int i = 0; i < size; i++)
            std::cout << arr[i] << " ";
        std::cout << "\n"
    }
    int main()
    {
        int size;
        std::cout << "\nEnter the number of Element：";
        std::cin >> size;
        int *arr = new int[size];
        std::cout << "\nEnter the unsorted elements: ";
        for (int i = 0; i < size; ++i)
        {
            std::cout << "\n";
            std::cin >> arr[i];
        }
        quickSort(arr, 0, size);
        std::cout << "Sorted array" << std::endl;
        show(arr, size);
        delete[] arr;
        return 0;
    }
}