#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> perm;
int visited[100];
int N;
int result;

void permutation(int k);

int main()
{
    std::cin >> N;

    permutation(0);

    std::cout << result;

    return 0;
}

void permutation(int k)
{
    if (k == N)
    {
        result++;
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        if (perm.size() == 0)
        {
            if (i == 0)
                continue;
            perm.push_back(i);
        }
        else
        {
            if (i == perm[k - 1] - 1 || i == perm[k - 1] + 1)
            {
                perm.push_back(i);
            }
            else
            {
                continue;
            }
        }
        permutation(k + 1);
        perm.pop_back();
    }
}