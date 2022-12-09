#include <iostream>

int *result;
int N;

void merge(int *arr, int left, int right)
{
    int middle = (left + right) / 2;
    int i = left;
    int j = middle + 1;
    int k = left;

    while (i <= middle && j <= right) //i가 중앙에, j가 끝에 도달할 때 까지 반복
    {
        if (arr[i] < arr[j]) // 좌측 배열보다 우측 배열이 더 클 경우
        {
            result[k++] = arr[i++]; //결과 배열에 좌측 배열 값 삽입.
        }
        else //우측 배열보다 좌측배열이 클 경우
        {
            result[k++] = arr[j++]; //결과 배열에 우측배열 값 삽입.
        }
    }

    while (i <= middle) //좌측 배열의 남은값 삽입.
    {
        result[k++] = arr[i++];
    }

    while (j <= right) // 우측 배열의남은 값 삽입.
    {
        result[k++] = arr[j++];
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = result[i]; //결과 배열의 값 원본 배열에 복사.
    }
}

void partition(int *arr, int left, int right)
{
    if (left < right)
    {
        int middle = (left + right) / 2;
        partition(arr, left, middle);
        partition(arr, middle + 1, right);
        merge(arr, left, right);
    }
}

int main()
{
    std::cin >> N;
    int *input = new int[N];
    result = new int[N];

    for (int i = 0; i < N; i++)
    {
        //std::cin >> input[i];
        input[i] = 20 - i;
    }
    partition(input, 0, N-1);
    for(int i = 0; i < N; i++)
    {
        std::cout << input[i] << " ";
    }
    return 0;
}