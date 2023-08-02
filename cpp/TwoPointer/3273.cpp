#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, X;

vector<int> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> X;
    sort(arr.begin(), arr.end());

    int l = 0, r = N-1, result = 0;

    while(l < r)
    {
        int sum = arr[l] + arr[r];
        if(sum == X)
        {
            l++; r--;
            result++;
        }
        else if(sum > X)
        {
            r--;
        }
        else{
            l++;
        }
    }

    cout << result << "\n";
    return 0;
}