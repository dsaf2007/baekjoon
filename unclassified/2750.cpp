#include <iostream>

int main()
{
    int size;
    std::cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for(int j =0; j<size-1;j++)
        if (arr[j] > arr[j + 1])
        {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << "\n";
    }
    return 0;
}