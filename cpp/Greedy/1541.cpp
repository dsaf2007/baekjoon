#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
int sum;

vector<string> splitted;

vector<string> split(string input, char delim)
{
    vector<string> ans;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, delim))
    {
        ans.push_back(temp);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string input;
    cin >> input;

    splitted = split(input, '-');

    for(int i = 0; i < splitted.size(); i++)
    {
        int temp;
        stringstream ss(splitted[i]);
        while(ss >> temp)
        {
            if(i == 0)
            {
                sum += temp;
            }
            else
            {
                sum -= temp;
            }
        }        
    }

    std::cout << sum << "\n";

    return 0;
}