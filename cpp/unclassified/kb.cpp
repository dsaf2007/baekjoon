#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v;
    for(int i = 1; i <= 9; i++)
    {
        v.push_back(i);
    }
    v.push_back(1);
    v.push_back(2);
    set<int> s;

    for(auto a : v)
    {
        s.insert(a);
    }
    v.clear();
    for(auto a : s)
    {
        v.push_back(a);
    }

    int mid = v[v.size()/2];
    vector<int> big;
    vector<int> small;
    for(auto a : v)
    {
        if(a < mid)
            small.push_back(a);
        else if( a > mid)
            big.push_back(a);
    }
    sort(big.begin(), big.end());
    sort(small.begin(), small.end(), greater<>());

    v.clear();
    v.push_back(mid);
    for(int i = 0; i < big.size(); i++)
    {
        v.push_back(big[i]);
        v.push_back(small[i]);
    }

    for(auto a : v)
    {
        cout << a << " ";
    }

    return 0;
}