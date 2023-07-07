#include <iostream>
#include <vector>

using namespace std;

int arr[4];
int check[4];
int n = 3;
int r = 3;

void permutation(int k)
{
    if(k == r)
    {
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }cout << "\n";
        return;
    }

    for(int i = 1; i <= 3; i++)
    {
        if(!check[i])
        {
            check[i] = 1;
            arr[k] = i;
            permutation(k+1);
            check[i] = 0;
        }
    }
}

void permutation_rep(int k)
{
    if(k == r)
    {
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }cout << "\n";
        return;
    }

    for(int i = 1; i <= 3; i++)
    {
        arr[k] = i;
        permutation_rep(k+1);
    }
}

void combination(int k, int idx)
{
    if(k == r)
    {
        for(int i = 0; i < 2; i++)
        {
            cout << arr[i] << " ";
        }cout << "\n";
        return;
    }

    for(int i = idx; i <= n; i++)
    {
        arr[k] = i;
        combination(k + 1, i + 1);
    }
}

void combination_rep(int k, int idx)
{
    if(k == r)
    {
        for(int i = 0; i < 2; i++)
        {
            cout << arr[i] << " ";
        }cout << "\n";
        return;
    }

    for(int i = idx; i <= n; i++)
    {
        arr[k] = i;
        combination(k + 1, i);
    }
}



int main()
{
    //순열
    cout << "순열 :\n";
    permutation(0);
    //중복순열
    cout << "===================\n중복순열 :\n";
    permutation_rep(0);

    n = 4;
    r = 3;
    //조합
    cout << "===================\n조합 :\n";
    combination(0,1);
    //중복조합
    cout << "===================\n중복조합 :\n";
    combination_rep(0, 1);

    return 0;
}

