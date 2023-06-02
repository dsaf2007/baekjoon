#include <iostream>
#include <vector>

int check[4][4];
int answer;

int main()
{
    int input[4][4];


    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cin >> input[i][j];
        }
    }

    for(int i = 0; i < 4; i++) //위
    {
        if(input[i][0] != 0 && check[i][0] == 0 )
        {
            answer++;
            check[i][0] = 1;
        }
        for(int j = 1; j < 4; j++)
        {
           int see = 1;
           for(int x = j-1; x >= 0; x--)
           {
                if(input[i][j] <= input[i][x])
                {
                    see = 0;
                }
           }
           if(see == 1 && check[i][j] == 0)
           {
                answer++;
                check[i][j] = 1;
           }
        }
    }

    for(int i = 0; i < 4; i++) //아래
    {
        if(input[i][3] != 0 && check[i][3] == 0 )
        {
            answer++;
            check[i][3] = 1;
        }
        for(int j = 2; j >= 0; j--)
        {
           int see = 1;
           for(int x = j+1; x < 4; x++)
           {
                if(input[i][j] <= input[i][x])
                {
                    see = 0;
                }
           }
           if(see == 1 && check[i][j] == 0)
           {
                answer++;
                check[i][j] = 1;
           }
        }
    }

    for(int j = 0; j < 4; j++) //왼
    {
        if(input[0][j] != 0 && check[0][j] == 0 )
        {
            answer++;
            check[0][j] = 1;
        }
        for(int i = 1; i < 4; i++)
        {
           int see = 1;
           for(int x = i-1; x >= 0; x--)
           {
                if(input[i][j] <= input[x][i])
                {
                    see = 0;
                }
           }
           if(see == 1 && check[i][j] == 0)
           {
                answer++;
                check[i][j] = 1;
           }
        }
    }

    for(int j = 0; j < 4; j++) //아래
    {
        if(input[3][j] != 0 && check[3][j] == 0 )
        {
            answer++;
            check[3][j] = 1;
        }
        for(int i = 2; i >= 0; i--)
        {
           int see = 1;
           for(int x = i+1; x <4 ; x++)
           {
                if(input[i][j] <= input[x][j])
                {
                    see = 0;
                }
           }
           if(see == 1 && check[i][j] == 0)
           {
                answer++;
                check[i][j] = 1;
           }
        }
    }

    std::cout << answer << std::endl;

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            std::cout << check[i][j] << " ";
        }
        std::cout << "\n";
    }
}