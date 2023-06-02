#include <iostream>

using namespace std;

int N;
int arr[101];
int op[4];
int min_num = 1000000000;
int max_num = -1000000000;

void sol(int k, int sum)
{
    if(k == N - 1)
    {
        if(sum > max_num)
        {
            max_num = sum;
        }
        if(min_num > sum)
        {
            min_num = sum;
        }
        return;
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            if(op[i] > 0)
            {
                op[i]--;
                if(i == 0) //덧셈
                {
                    sol(k+1, sum + arr[k+1]);
                }
                else if(i == 1)//뺄셈
                {
                    sol(k+1, sum - arr[k+1]);
                }
                else if(i == 2)//곱셈
                {
                    sol(k+1, sum * arr[k+1]);
                }
                else
                {
                    sol(k+1, sum / arr[k+1]);
                }
                op[i]++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < 4; i++)
    {
        cin >> op[i];
    }

    sol(0,arr[0]);

    std::cout << max_num << "\n" << min_num <<"\n";

    return(0);
}