#include <iostream>
#include <cstdlib>

int N;
int max;
int min
int cal[4];
int result;
int num [12];
void calculate(int k)
{
    if( k == N)
    {
        std::cout << max << "\n" << min;
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            if( cal[i] != 0)
            {
                result += num[k];
                cal[i] --;
                calculate(k+1);
                cal[i] ++;
            }
        }
    }
}

int main()
{
    std::cin >> N;
    int temp;
    for(int i = 0; i < N; i++)
    {
        std::cin >> temp;
        num[i] = temp;
    }
    for(int i = 0; i < 4; i++)
    {   
        std::cin >> temp;
        cal[i] = temp; 
    }
    result = num[0];
    calculate(0);


    return 0;
}