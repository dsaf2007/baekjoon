#include <iostream>

int N, S, result;
int arr[21];
using namespace std;


void solution(int k, int sum)
{
    if(k == N)
    {
        if(sum == S)
        {
            result++;
        }
        return;
    }
    else
    {
        solution(k+1,sum);
        solution(k+1, sum+arr[k]);
    }
}
int main()
{
    ios_base::sync_with_stdio(fasle);
    cin.tie(0);

    std::cin >> N >> S;

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    solution(0,0);
    return 0;
}