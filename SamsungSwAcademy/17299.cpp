#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        int input;
        cin >> input;

        int l;
        int r;
        int result = INT16_MAX;
        for(int i = 10; input / i > 0; i *= 10)
        {
            l = input / i;
            r = input % i;
            result = min(result, l + r);
        }

        cout << result;
    }

    return 0;
}