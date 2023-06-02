#include <iostream>
#include <vector>

int main()
{
    std::vector<std::string> input;
    int N, M;
    char color;
    int cnt, cnt2;
    int output = INT16_MAX;

    std::cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        std::string temp;
        std::cin >> temp;
        input.push_back(temp);
    }
    // for(int i=0;i<N;i++)
    // {
    //     std::cout << input[i] << std::endl;
    // }

    for (int x = 0; x < N - 7; x++)
    {
        for (int y = 0; y < M - 7; y++)
        {
            if (input[x][y] == 'W')
            {
                color = 'W';
            }
            else
            {
                color = 'B';
            }
            cnt = 0;
            cnt2 = 0;
            for (int i = x; i < x + 8; i++)
            {
                for (int j = y; j < y + 8; j++)
                {
                    if (i % 2 == 0)
                    {
                        if (j % 2== 0)
                        {
                            if (input[i][j] == color)
                                cnt++;
                            else
                                cnt2++;
                        }
                        else
                        {
                            if (input[i][j] == color)
                                cnt2++;
                            else
                                cnt++;
                        }
                    }
                    else
                    {
                        if (j % 2 == 0)
                        {
                            if (input[i][j] == color)
                                cnt2++;
                            else
                                cnt++;
                        }
                        else
                        {
                            if (input[i][j] == color)
                                cnt++;
                            else
                                cnt2++;
                        }
                    }
                }
            }
            if(cnt < cnt2)
            {
                if(output > cnt)
                {
                    output = cnt;
                }
            }
            else
            {
                if(output > cnt2)
                {
                    output = cnt2;
                }
            }
        }
    }
    std::cout << output;

    return 0;
}