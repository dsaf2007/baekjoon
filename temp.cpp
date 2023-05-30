#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


int test_case;
vector<pair<char, int> > num; // 이름, 갯수
vector<pair<char, int> > q; // 이름, 순번
vector<char> result;
int main() {
		ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> test_case;
    string cmd;
    int idx = 0;
    for(int t = 0; t < test_case; t++)
    {
        cin >> cmd;

        if(cmd == "enqueue")
        {
            char temp;
            cin >> temp;
            q.push_back({temp,idx++});

            auto it = find_if(num.begin(),num.end(), [=](pair<char, int> &p){return p.first == temp;});
            if(it == num.end())
            {
                num.push_back({temp, 1});
            }
            else
            {
                it->second++;
            }
            sort(num.begin(), num.end(), [](pair<char,int> &a, pair<char, int> &b) 
            {
                return a.second > b.second;
            });// 갯수 많은 순으로 정렬

            sort(q.begin(), q.end(), [](pair<char,int> &a, pair<char,int> &b){return a.second < b.second;}); // 들어온 순으로 정렬
            
        }
        else if(cmd == "dequeue")
        {
            //디큐
            vector<char> ch;
            ch.clear();
            int ch_num = num[0].second;
            ch.push_back(num[0].first);

            for(int i = 1; i < num.size(); i++)//같은 개수가 여러개일 경우
            {
                if(num[i].second == ch_num)
                    ch.push_back(num[1].first);
            }

            auto it = find_if(q.begin(), q.end(), [=](pair<char, int> &a){return a.first == ch[0];});
            int cur_idx = it->second;
            int k = 0;
            for(int i = 1; i < ch.size(); i++)//같은 캐릭터 중 가장 작은 인덱스 반환
            {
                auto it2 = find_if(q.begin(), q.end(), [=](pair<char, int> &a){return a.first == ch[i];});
                int temp_idx = it2->second;
                if(temp_idx < cur_idx)
                {
                    cur_idx = temp_idx;
                    k = i;
                }
            }

            auto out = find_if(q.begin(), q.end(), [=](pair<char, int> &a){return a.second = cur_idx;});
			char temp = out->first;
            result.push_back(temp);
            num[k].second--;
            remove_if(q.begin(), q.end(), [=](pair<char, int> &a){return a.second = cur_idx;}); //삭제;

            sort(num.begin(), num.end(), [](pair<char,int> &a, pair<char, int> &b) 
            {
                return a.second > b.second;
            });// 갯수 많은 순으로 정렬
        }

    }
		
    for(auto o : result)
    {
        cout << o << " ";
    }
    return 0;

}