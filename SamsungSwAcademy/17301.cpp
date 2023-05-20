#include <iostream>
#include <vector>
#include <deque>

using namespace std;


//int arr[100001];
vector<long> arr;
long n, q, temp, sum;
int main()
{
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
        for(int i = n + 1; i <= 100000; i++)
        {
            int temp = arr[i-1] + (arr[i - 1] - arr[i - n - 1])/n;
            arr.push_back(temp);
        }

        cin >> q;
        cout << "#" << t << " ";
        for(int i = 0; i < q; i++)
        {
            cin >>temp;
            cout << arr[temp] - arr[temp-1]<< " ";
        }cout << "\n";
    }
    return 0;
}