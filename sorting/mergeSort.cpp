#include <iostream>

using namespace std;
/**
 * @brief Merges two subarrays of array[].
 *  * first subarray is arr[begin..mid]
 *    second array is arr[mid+1..end]
 * @param array 
 * @param left 
 * @param mid 
 * @param right 
 */
void merge(int array[], int const left,int const mid,int const right)
{
    auto const subArrayOne = mid -left + 1;
    auto const subArrayTwo = right - mid;
    //create temp arrays
    auto *leftArray = new int[subArrayOne];
    auto *rightArray = new int[subArrayTwo];
    //copy data to temp arrays leftArray[] and rightArray[]
    for(auto i = 0; i < subArrayOne; i++)
    {
        leftArray[i] = array[left + i];
    }
    for(auto j = 0; j < subArrayTwo; j++)
    {
        rightArray[j] = array[mid + 1+j];
    }
    auto indexOfSubArrayOne = 0, //Initial index of first sub-array
         indexOfSubArrayTwo = 0; //Initail iddex of second sub-array
    int indexOfMergedArray = left; //Initial index of merged array
    //merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if(leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    //copy the remaining elements of right[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray++] = subArrayOne[indexOfSubArrayOne++];
    }

      while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray++] = subArrayOne[indexOfSubArrayTwo++];
    }

    
    
}
void mergeSort(int arr[], int begin, int end)
{
    if(begin >= end)
        return;
    auto mid = beign + (end - begin)/2;
    mergeSort(arr,begin,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,begin,mid,end);
}
 auto filteredGraph = withLaneChanges ? (withAreas ? (graph.withAreasAndLaneChanges(routingCostId) : graph.withLaneChanges(routingCostId): withAreas ? graph.withAreasWithoutLaneChanges(routingCostId) ): graph.withoutLaneChanges(routingCostId);