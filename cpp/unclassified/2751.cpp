#include <iostream>
#include <algorithm>

// 정렬 알고리즘 복습하기.
// 2022.12.09 할일.
// bubble sort, quick sort, merge sort 정도 해보기.
int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(null);
    int N;
    std::cin >> N;
    int *input = new int[N];

    for (int i = 0; i < N; i++)
    {
        std::cin >> input[i];
    }

    std::sort(input, input + N);

    for (int i = 0; i < N; i++)
    {
        std::cout << input[i] << "\n";
    }
    return 0;
}