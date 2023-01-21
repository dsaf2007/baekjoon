#include <iostream>
#include <vector>

std::string input_str;
int n;
std::vector<int> result;
int sum[222222][26];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);

    std::cin >> input_str;
    std::cin >> n;

    for (int i = 0; i < input_str.length(); i++)
    {
        if (i != 0)
        {
            for (int k = 0; k < 26; k++)
            {
                sum[i][k] = sum[i - 1][k];
            }
        }

        int temp = input_str[i] - 'a';
        sum[i][temp]++;
    }

    for (int i = 0; i < n; i++)
    {
        char c;
        int a, b;
        std::cin >> c >> a >> b;

        int temp = c - 'a';

        if (a == 0)
        {
            std::cout << sum[b][temp] - 0 << "\n";
        }
        else
        {
            std::cout << sum[b][temp] - sum[a - 1][temp] << "\n";
        }
    }

    for (auto a : result)
    {
        std::cout << a << "\n";
    }

    return 0;
}