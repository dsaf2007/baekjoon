#include <iostream>
#include <vector>

using namespace std;

int n;
int k;
int sum, result;
int arr[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = n -1; i >= 0; i--)
    {
        while(arr[i] <= k)
        {
            k -= arr[i];
            result++;
        }
    }

    cout << result << "\n";

    return 0;
}