#include <iostream>
#include <string>
#include <cstdbool>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;

bool isAdj(pair<int, int> a, pair<int, int> b);
void getSeat(int idx);
void chooseSeat(int idx);
void getSeats(int r, int c, int idx, int &max, vector<pair<int, int>> &seats);
int getFriendsNear(int r, int c, int idx);
int getEmptySeats(int r, int c);
int getScore(int r, int c);
void printSeats(int n);

int seat[21][21];
int student[401][4];
int order[401];
int N;

void printSeats(int n)
{
    cout << "=========seats=========\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << seat[i][j] << " ";
        }cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    // 학생 선호도 입력
    for (int i = 0; i < N*N; i++)
    {
        int name;
        cin >> name;
        order[i] = name;
        for (int j = 0; j < 4; j++)
        {
            cin >> student[name][j]; //선호1, 2, 3, 4
        }
    }

    // for (int i = 0; i < N*N; i++)
    //     cout << order[i] << " ";
    // cout << "\n";

    
    for(int i = 0; i < N*N; i++)
    {
        chooseSeat(order[i]); //idx에 name 입력
        //printSeats(N);
    }

    int result = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            result += getScore(i, j);
            //cout << "name : " << seat[i][j] << " score : " << getScore(i,j) << "\n";
        }
    }

    cout << result << "\n";

    return 0;
}

bool isAdj(int x1, int y1, int x2, int y2)
{
    if (abs(x1 - x2) + abs(y1 - y2) == 1)
        return true;
    return false;
}

void chooseSeat(int idx)
{
    int max_fav = 0;
    vector<pair<int, int>> seats;
    seats.clear();
    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < N; c++)
        {
            getSeats(r, c, idx, max_fav, seats);
            //cout << "sat on " << r << " " << c << " \n";
        }
    }
    if(seats.size() > 1) // 조건 1을 만족하는 자리가 여러개인 경우
    {
        int max_empty = 0;
        for(auto s : seats)
        {
            int empty_seats = getEmptySeats(s.first, s.second);
            if(empty_seats >= max_empty)
            {
                max_empty = empty_seats;
            }
        }
        seats.erase(remove_if(seats.begin(), seats.end(), 
        [=](auto x)-> bool {
            return getEmptySeats(x.first, x.second) < max_empty;
        }), seats.end()); // 빈 좌석이 최대인 경우만 남김

        sort(seats.begin(), seats.end(), 
        [=](auto it1, auto it2) -> bool {
            if(it1.first == it2.first)
            {
                return it1.second < it2.second;
            }
            return it1.first < it2.first;
        }); //행, 열 번호를 기준으로 오름차순 정렬
        // pair<int, int> choosed_seat = seats[0];
        // seat[choosed_seat.first][choosed_seat.second] = idx; // 좌석에 학생번호 입력
        // return;
    }
    seat[seats[0].first][seats[0].second] = idx;
}

void getSeats(int r, int c, int idx, int &max, vector<pair<int, int>> &seats)
{
            // if (i < 0 || i >= N || j < 0 || j >= N)
            //     continue; // out of range

            int favorites = getFriendsNear(r, c, idx);

           // cout << "fav : " << favorites << "\n";

            if (seat[r][c] == 0 && favorites >= max) // 좋아하는 친구가 더 많으면 vector clear
            {
                if (favorites > max)
                {
                    max = favorites;
                    seats.clear();
                    //cout << "max : " << max << "\n";
                }
                seats.push_back({r, c});
            }
}

int getFriendsNear(int r, int c, int idx)
{
    int fav = 0;
    for (int i = r - 1; i <= r + 1; i++)
    {
        if(i < 0 || i >=N) continue;
        for (int j = c - 1; j <= c + 1; j++)
        {
            if (j < 0 || j >= N) continue; // out of range
            if(!isAdj(r,c,i,j)) continue;
            
            for (int k = 0; k < 4; k++)
            {
                if (seat[i][j] == student[idx][k])
                {
                    fav++;
                }
            }
        }
    }
    return fav;
}

int getEmptySeats(int r, int c)
{
    int empty = 0;
    for (int i = r - 1; i <= r + 1; i++)
    {
        for (int j = c - 1; j <= c + 1; j++)
        {
            if (i < 0 || i >= N || j < 0 || j >= N)
                continue; // out of range
            if(!isAdj(r,c,i,j)) continue;
            if (seat[i][j] == 0)
                empty++;
        }
    }
    return empty;
}

int getScore(int r, int c)
{
    int name = seat[r][c];

    int score = 0;
    for (int i = r - 1; i <= r + 1; i++)
    {
        for (int j = c - 1; j <= c + 1; j++)
        {
            if (i < 0 || i >= N || j < 0 || j >= N)
                continue; // out of range
            if(!isAdj(r,c,i,j)) continue;
            for(int f = 0; f < 4; f++)
            {
                if(seat[i][j] == student[name][f])
                {
                    score++;
                }
            }
        }
    }
    if(score == 0) return 0;
    return pow(10, score -1); // 0 - 0 , 1 - 1, 2 - 10, 3 - 100, 4 - 1000
}