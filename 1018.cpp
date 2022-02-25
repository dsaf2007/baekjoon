#include <iostream>
#include <vector>

int main()
{
    int N, M, flag;
    std::cin >> N >> M;
    int cnt = 0;
    std::vector<std::string> input;
    //std::vector<std::string> chess;
    int wcnt = 0;
    int bcnt = 0;
    int tmpcnt;

    for (int i = 0; i < M; i++)
    {
        std::string input_string;
        std::cin >> input_string;
        input.push_back(input_string);
    }
    std::vector<std::vector<char>> chess(N,std::vector<char>(M));
    std::cout << "111" <<std::endl;
    for (int i = 0; i < M - 7; i++) //gi체스판 내에서 8*8자르기
    {
        for (int j = 0; j < N - 7; j++)
        {
            tmpcnt = 0;
            std::cout << tmpcnt << std::endl;
            for (int k = 0; k < 8; k++)
            {
                for (int z = 0; z < 8; z++)
                {
                    chess[k][z] = input[k + i][z + j]; // 자른 체스판 입력
                    std::cout << chess[k][z];
                }
            }

            if (chess[0][0] == 'W')
            {
                flag = 'W';
            }
            else if (chess[0][0] == 'B')
            {
                flag = 'B';
            }
            std::cout << flag;
            for (int k = 0; k < 8; k++)
            {
                for (int z = 0; z < 8; z++)
                {
                    if (k % 2 == 0 && z % 2 == 0)
                    {
                        if (chess[k][z] != flag)
                        {
                            tmpcnt++;
                        }
                    }
                    else if (k % 2 == 1 && z % 2 == 0)
                    {
                        if (chess[k][z] == flag)
                        {
                            tmpcnt++;
                        }
                    }
                    else if (k % 2 == 0 && z % 2 == 1)
                    {
                        if (chess[k][z] == flag)
                        {
                            tmpcnt++;
                        }
                    }
                    else if (k % 2 == 1 && z % 2 == 0)
                    {
                        if (chess[k][z] != flag)
                        {
                            tmpcnt++;
                        }
                    }
                    std::cout << tmpcnt <<std::endl;
                }
            }
            if (cnt == 0)
            {
                cnt = tmpcnt;
            }
            else if (tmpcnt <= cnt)
            {
                cnt = tmpcnt;
            }
        }
    }
}