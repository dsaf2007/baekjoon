#include <iostream>
#include <string>

int main()
{
    int n;
    std::cin >> n;

    int num = 666;
    int cnt = 1;
    int i = 0;

    while (cnt != n)
    {
        num++;
        std::string num_str = std::to_string(num);
        for (int j = 0; j < num_str.length() - 2; j++)
        {
            if (num_str[j] == '6')
            {
                if (num_str[j + 1] == '6' && num_str[j + 2] == '6')
                {
                    cnt++;
                    break;
                }
                else
                    j++;
            }
        }
    }

    std::cout << num;

    return 0;
}