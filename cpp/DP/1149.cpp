#include <iostream>
#include <algorithm>

int n;
int red[1000];
int green[1000];
int blue[1000];

//인접한 집 끼리의 색은 달라야 한다.


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);


    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cin >> red[i] >> green[i] >> blue[i];
    }

    for(int i = 1; i < n; i++)
    {
        red[i] += std::min(green[i-1], blue[i-1]);
        green[i] += std::min(red[i-1], blue[i-1]);
        blue[i] += std::min(green[i-1], red[i-1]);
    }

    int result = std::min({red[n-1], green[n-1], blue[n-1]});

    std::cout << result;
    

    return 0;
}