#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int T;
int N;
vector<pair<int, int>> convi;
pair<int, int> home;
pair<int, int> festival;

int dist(pair<int, int> a, pair<int, int> b)
{
    return (abs(a.first - b.first) + abs(a.second - b.second));
}

bool bfs()
{
    queue<pair<int, int>> q;
    q.push({home.first, home.second});

    while(!q.empty())
    {
        pair<int, int> inq = q.front();
        q.pop();

        if(dist(festival, inq) <= 1000) return true;

        for(auto c : convi)
        {
            if(dist(inq, c) <= 1000)
            {
                q.push(c);
                convi.erase(remove_if(convi.begin(), convi.end(), [=] (auto p) -> bool {
                    return (c.first == p.first && c.second == p.second);
                }), convi.end());
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    for(int t = 0; t < T; t++)
    {
        cin >> N;
        cin >> home.first >> home.second;
        for(int n = 0; n < N; n++)
        {
            int x, y;
            cin >> x >> y;
            convi.push_back({x, y});
        }
        cin >> festival.first >> festival.second;

        if(bfs()) cout << "happy\n";
        else cout << "sad\n";

        convi.clear();

    }

    return 0;
}