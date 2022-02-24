#include <iostream>
#include <vector>

int main()
{
    int N, M, flag;
    std::cin >> N >> M;
    int cnt = 0;
    std::vector<std::string> input;
    std::vector<std::string> chess;
    int wcnt = 0;
    int bcnt = 0;

    for (int i = 0; i < N; i++)
    {
        std::string input_string;
        std::cin >> input_string;
        input.push_back(input_string);
    }

    for (int i = 0; i < N - 8; i++) //체스판 내에서 8*8자르기
    {
        for (int j = 0; j < M - 8; j++)
        {
            wcnt = 0;
            bcnt = 0;

            for (int k = 0; k < 8; k++)
            {
                for (int z = 0; z < 8; z++)
                {
                    chess[k][z] = input[k + i][z + j]; // 자른 체스판 입력
                }
            }
            
            if (chess[0][0] == 'W')
            {
                bcnt++;
            }
            else if (chess[0][0] == 'B')
            {
                wcnt++;
            }

            chess[0][0] = 'W';
            flag = 'W';
            for (int k = 0; k < 8; k++)
            {
                for (int z = 0; z < 8; z++)
                {
                    if (k % 2 == 0 && z % 2 == 0)
                    {
                        if (chess[k][z] != flag)
                        {
                            wcnt++;
                        }
                    }
                    else if (k % 2 != 1 && z % 2 == 0)
                    {
                        if (chess[k][z] == flag)
                        {
                            wcnt++;
                        }
                    }
                    else if (k % 2 == 0 && z % 2 == 1)
                    {
                        if (chess[k][z] == flag)
                        {
                            wcnt++;
                        }
                    }
                    else if (k % 2 == 1 && z % 2 == 0)
                    {
                        if (chess[k][z] != flag)
                        {
                            wcnt++;
                        }
                    }
                }
            }
        }

        chess[0][0] = 'B';
        flag = 'B';
        for (int k = 0; k < 8; k++)
        {
            for (int z = 0; z < 8; z++)
            {
                if (k % 2 == 0 && z % 2 == 0)
                {
                    if (chess[k][z] != flag)
                    {
                        bcnt++;
                    }
                }
                else if (k % 2 != 1 && z % 2 == 0)
                {
                    if (chess[k][z] == flag)
                    {
                        bcnt++;
                    }
                }
                else if (k % 2 == 0 && z % 2 == 1)
                {
                    if (chess[k][z] == flag)
                    {
                        bcnt++;
                    }
                }
                else if (k % 2 == 1 && z % 2 == 0)
                {
                    if (chess[k][z] != flag)
                    {
                        bcnt++;
                    }
                }
            }
        }

        int tmpcnt;
        if (wcnt <= bcnt)
        {
            tmpcnt = wcnt;
        }
        else
        {
            tmpcnt = bcnt;
        }

        if (cnt == 0)
        {
            cnt = tmpcnt;
        }
        else if (tmpcnt <= cnt)
        {
            cnt = tmpcnt;
        }
        std::cout <<cnt;
    }

    std::cout << cnt;
}

// for (int i = 0; i < N; i++) // 8*8을 잘라내서 구함.
// {
//     for (int j = 0; j < M; j++)
//     {
//         if (i % 2 == 0 && j % 2 == 0)
//         {
//             if (chess[i][j] != flag)
//             {
//                 cnt++;
//             }
//         }
//         else if (i % 2 != 1 && j % 2 == 0)
//         {
//             if (chess[i][j] == flag)
//             {
//                 cnt++;
//             }
//         }
//         else if (i % 2 == 0 && j % 2 == 1)
//         {
//             if (chess[i][j] == flag)
//             {
//                 cnt++;
//             }
//         }
//         else if (i % 2 == 1 && j % 2 == 0)
//         {
//             if (chess[i][j] != flag)
//             {
//                 cnt++;
//             }
//         }
//     }
// }

// }