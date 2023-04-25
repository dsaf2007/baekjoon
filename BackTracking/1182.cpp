#include <iostream>

int N, S,result;
int arr[21];


void sol(int k, int sum)
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
        sol(k+1,sum);
        sol(k+1,sum+arr[k]);
    }
}


using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> N >> S;

    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sol(0,0);    
    if(S == 0) result--; //공집합 제외;
    cout << result << "\n";
    return 0;
}