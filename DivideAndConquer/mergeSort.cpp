#include <iostream>

using namesapce std;

int arr[10];
int temp[10];
void merge(int start, int end;)
{
    int mid = (start + end)/2;
    int l = start;
    int r = end;

    for(int i = start; i <= end; i++)
    {
        if(r == end) temp[i] = arr[l++];
        else if(l == mid) temp[i] == arr[r++];
        else if(arr[l] <= arr[r]) temp[i] = arr[l++];
        else temp[i] = arr[r++];
    }
    for(int i =  start; i <= end; i++)
    {
        arr[i] = temp[i];
    }
}

void mergeSort(int start, int end)
{
    if(start == end) return;
    int mid = (start + end) / 2;
    mergeSort(start, mid);
    mergeSort(mid, end);
    merge();
}
int main()
{
    for(int i = 10; i > 0; i--)
    {
        arr[10-i] = i;
    }
    return 0;
}