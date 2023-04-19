#include <iostream>


using namespace std;

int N, M;

int arr[9];
int visited[9];
int num[9];


void permutation(int k)
{
    if(k == M)
    {
        for(int i = 0; i < k; i++)
        {
            cout << arr[i] << " ";
        }cout << "\n";
        
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            if(visited[i] == 0)
            {
                arr[k] = num[i];
                visited[i] = 1;
                permutation(k+1);
                visited[i] = 0;
            }       
            
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < 9; i++)
    {
        num[i] = i+1;
    }

    permutation(0);

    return 0;
}