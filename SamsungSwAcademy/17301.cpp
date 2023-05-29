#include <iostream>
#include <vector>
#include <deque>

using namespace std;


//int arr[100001];
vector<long> arr;
long n, q, temp, size;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test_case;
    cin >> test_case;
    
    for(int t = 1; t <= test_case; t++)
    {
        cin >> n;
        arr.clear();
        arr.push_back(0);
        for(int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            //arr[i] = arr[i-1] + temp;
            temp += arr[i-1];
            arr.push_back(temp);
        }
        int duplicate = 0;
        for(int i = n + 1; i <= 100000 + n; i++)
        {
            int temp = arr[i-1] + (arr[i - 1] - arr[i - n - 1])/n;
            arr.push_back(temp);
            if(arr[i] - arr[i-1] == arr[i -1] - arr[i-2])
                duplicate++;
            if(duplicate == n )
            {
                size = i;
            }
        }
        cin >> q;
        cout << "#" << t << " ";
        for(int i = 0; i < q; i++)
        {
            cin >>temp;
            if(temp <= size)
                cout << arr[temp] - arr[temp-1]<< " ";
            else
                cout << arr[size] - arr[size-1]<< " ";
        }cout << "\n";
    }
    return 0;
}