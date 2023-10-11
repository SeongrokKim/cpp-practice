#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    deque<pair<int, int>> state;
    for(auto station : stations){
        state.push_back({station-w,station+w});
    }
    int s = 1;
    int e = 1;
    while(true){
        pair<int, int> now;
        if(state.empty()){
            if(s > n){
                break;
            }
            else{
                e = n;
                int cnt = e - s + 1;
                if (cnt % (2*w+1) == 0){
                    answer += cnt / (2*w+1);
                }
                else{
                    answer += cnt / (2*w+1) + 1;
                }
                break;
            }
        }
        now = state.front();
        int fir = 1;
        if (now.first > 0){
            fir = now.first;
        }
        int sec = now.second;
        e = fir - 1;
        int cnt = e - s + 1;
        if (cnt > 0){
            if (cnt % (2*w+1) == 0){
                answer += cnt / (2*w+1);
            }
            else{
                answer += cnt / (2*w+1) + 1;
            }
        }
        s = sec + 1;
        state.pop_front();
    }
    return answer;
}