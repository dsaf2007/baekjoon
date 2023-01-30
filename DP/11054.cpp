#include <iostream>
#include <algorithm>

int n;
int arr[1000];
int ldp[1000];
int rdp[1000];
int result[1000];
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    //좌측부터 증가하는 부분수열
    for(int i = 0; i < n; i++)
    {
        ldp[i] = 1;
        for(int j = 0; j <= i; j++)
        {
            if(arr[i] > arr[j] && ldp[i] < ldp[j] + 1)
            {
                ldp[i] = ldp[j] + 1;
            }
        }
    }
    //우측부터 증가하는 부분수열
    for(int i = n -1; i >= 0; i--)
    {
        rdp[i] = 1;
        for(int j = n -1; j >= i; j--)
        {
            if(arr[i] > arr[j] && rdp[i] < rdp[j] + 1)
            {
                rdp[i] = rdp[j] + 1;
            }
        }
    }
    //합치기
    for(int i = 0; i < n; i++)
    {
        result[i] = rdp[i] + ldp[i] - 1;
    }

    std::cout << *std::max_element(result, result + n);
    return 0;
}