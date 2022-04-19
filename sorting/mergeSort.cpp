#include <iostream>

using namespace std;

void merge(int *arr, int l, int m, int r)
{
    int i,j,k;
    int n1 = m - l +1;
    int n2 = r-m;
    int *L = new int[n1];
    int *R = new int[n2];
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[l+i];
    }
    for(int j = 0; j < n2; j++)
    {
        R[i] = arr[m+1+j];
    }
    i = 0;
    j = 0;
    k = l;
    while(i < n1 || j < n2)
    {
        if(j >= n2 || (i < n1 && L[i] <= R[j]))
        {
            arr[k] = L[i];
            i++;
        }else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    delete[] L;
    delete[] R;
}
void mergeSort(int *arr, int l, int r)
{
    if(l < r)
    {
        int m = l + (r -l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}