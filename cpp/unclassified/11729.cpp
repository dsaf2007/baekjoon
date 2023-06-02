#include <iostream>

using namespace std;

int N;

void hanoi(int a, int b, int k)
{
    if(k == 1)
    {
        cout << a << " " << b << "\n";
        return;
    }
    hanoi(a, 6 - a - b, k-1);
    cout << a << " " << b << "\n";
    hanoi(6 - a - b, b, k-1);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //cin >> N;

    int len = 4;
    for(int i = 0, j = 3; i<=j; i++, j-- )
    {
        cout << i << ":" << j << "\n";
    }
    //cout << (1<<N) - 1 << "\n";
    //hanoi(1, 3, N);
    return 0;
}