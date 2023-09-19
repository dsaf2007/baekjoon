#include <iostream>
#include <vector>
#include <algorithm>

int T, N;
using namespace std;

vector<pair<int, int>> input;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        input.clear();
        cin >>N;

        for(int n = 0; n < N; n++)
        {
            int a, b;
            cin >> a >> b;
            input.push_back({a,b});
        }

        sort(input.begin(), input.end(),
        [](const pair<int, int> a, const pair<int,int> b)-> bool
        {
            if(a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first < b.first;
        });
        //sort(input.begin(), input.end());

        int result = 1;
        int temp = 0;
        for(int i = 0; i < N; i++)
        {
            if(input[temp].second > input[i].second)
            {
                result++;
                temp = i;
            }
        }
        cout << "result : " << result << "\n";
    }
    return 0;
}