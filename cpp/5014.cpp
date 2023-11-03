#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int F, S, G, U, D;
int ud[2];
int line[1000001];
void bfs()
{
    queue<pair<int,int>> q;
    q.push({S, 0});

    while(!q.empty())
    {
        pair<int, int> inq;
        inq = q.front();
        q.pop();

        for(int i = 0; i < 2; i++)
        {
            int next = inq.first + ud[i];

            if(next == G)
            {
                line[next] = inq.second + 1;
                return;
            } 

            if(next <= 0 || next > F) continue;
            if(line[next] > -1) continue;

            line[next] = inq.second + 1;
            
            q.push({next, inq.second + 1});
        }
    }
}
int main()
{
    cin >> F >> S >> G >> U >> D;
    ud[0] = U;
    ud[1] = -D;
    for(int i = 0; i < 1000001; i++)
    {
        line[i] = -1;
    }
    if(S == G)
    {
        cout << "0\n";
        return 0;
    }
    if((S > G && D == 0) || (S < G && U ==0))
    {
        cout << "use the stairs\n";
        return 0;
    } 
        
    
    bfs();

    if(line[G] == -1) cout << "use the stairs\n";
    else cout << line[G] << "\n";
    return 0;
}