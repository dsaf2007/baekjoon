#include <iostream>
#include <math.h>

using namespace std;

int N, r, c;
int move_num, result;

void rec(int start_x, int start_y, int size)
{

    if(start_x == r && start_y == c)
    {
        cout << result << "\n";
        return;
    }

    if(r < start_x + size && r >=start_x && c < start_y + size && c >= start_y)
    {
        rec(start_x, start_y, size/2);
        rec(start_x, start_y + size/2, size/2);
        rec(start_x + size/2, start_y, size/2);
        rec(start_x + size/2, start_y +size/2, size/2);
    }
    else
    {
        result += size * size;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> r >> c;

    int init_size = pow(2, N);

    rec(0,0, init_size);

    //cout << result << "\n";


    return 0;
}