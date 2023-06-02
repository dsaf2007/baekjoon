#include <iostream>

using namespace std;

int n;
int arr[128][128];

int w, b;

void divide(int start_x, int start_y, int size)
{
    int color = arr[start_x][start_y];
    for(int i = start_x; i < start_x + size; i++)
    {
        for(int j = start_y; j < start_y + size; j++)
        {
            if(arr[i][j] != color)
            {
                divide(start_x, start_y, size/2);
                divide(start_x+ size /2 , start_y,size/2);
                divide(start_x, start_y + size/2, size/2);
                divide(start_x + size/2, start_y + size/2, size/2);
                return;
            }
        }    
    }
    if(color == 0) w++;
    else b++;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >>arr[i][j];
        }
    }

    divide(0,0,n);

    std::cout << w << "\n" << b;
}