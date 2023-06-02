#include <iostream>
#include <vector>

void combination(int idx, int k,std::vector<int> arr);
std::vector<std::vector<int>> combi;
    std::vector<int> visited(3,0);
int main()
{
    
    std::vector<int> arr(5,0);

    combination(0,0,arr);

    std::cout << combi.size() <<std::endl;

    for(auto x : combi)
    {
        for(auto i : x)
        {
            std::cout << i << " ";
        }
        std::cout<< "\n";
    }

    return 0;

}

void combination(int idx, int k,std::vector<int> arr)
{
    if(k == 3)
    {
        combi.push_back(arr);
        return;
    }
    else{
        for(int i = idx; i < 5; i++)
        {
            if(visited[i] == 1) continue;

            visited[i] = 1;
            arr[i] =i;
            combination(i, k+1, arr);
            visited[i] = 0;
        }
    }
}