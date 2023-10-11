#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string str, char c) {
    istringstream iss(str);
    string buffer;
 
    vector<string> result;

    while (getline(iss, buffer, c)) {
        result.push_back(buffer); 
    }
 
    return result;
}

bool compare(vector<string> a, vector<string> b){
    vector<string> at = split(a[1], ':');
    vector<string> bt = split(b[1], ':');
    if(stoi(at[0]) == stoi(bt[0])){
        return stoi(at[1]) < stoi(bt[1]);
    }
    return stoi(at[0]) < stoi(bt[0]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    deque<pair<string, int>> left_homework;
    sort(plans.begin(), plans.end(), compare);
    vector<string> now = split(plans[0][1], ':');
    string plan = plans[0][0];
    for(int i=0; i<plans.size(); i++){
        vector<string> next = split(plans[i][1], ':');
        if(stoi(next[0]) < stoi(now[0])){
            int left_time = (stoi(now[0]) - stoi(next[0]))*60 + stoi(now[1]) - stoi(next[1]);
            left_homework.push_back({plan, left_time});
        }
        else if(stoi(next[0]) == stoi(now[0]) && stoi(next[1]) < stoi(now[1])){
            int left_time = stoi(now[1]) - stoi(next[1]);
            left_homework.push_back({plan, left_time});
        }
        else{
            if (i != 0){
                answer.push_back(plan);
            }
            int left_time = (stoi(next[0]) - stoi(now[0]))*60 + stoi(next[1]) - stoi(now[1]);
            while(!left_homework.empty()){
                if (left_homework.back().second < left_time){
                    answer.push_back(left_homework.back().first);
                    left_time = left_time - left_homework.back().second;
                    left_homework.pop_back();
                }
                else if(left_homework.back().second == left_time){
                    answer.push_back(left_homework.back().first);
                    left_homework.pop_back();
                    break;
                }
                else{
                    pair<string, int> update = {left_homework.back().first, left_homework.back().second-left_time};
                    left_homework.pop_back();
                    left_homework.push_back(update);
                    break;
                }
            }
            
        }
        int after_h = 0;
        int after_m = 0;
        if(stoi(next[1]) + stoi(plans[i][2]) > 120){
            after_h = stoi(next[0]) + 2;
            after_m = stoi(next[1]) + stoi(plans[i][2]) - 120;
        }
        else if(stoi(next[1]) + stoi(plans[i][2]) > 60){
            after_h = stoi(next[0]) + 1;
            after_m = stoi(next[1]) + stoi(plans[i][2]) - 60;
        }
        else{
            after_h = stoi(next[0]);
            after_m = stoi(next[1]) + stoi(plans[i][2]);
        }
        now[0] = to_string(after_h);
        now[1] = to_string(after_m);
        plan = plans[i][0];
    }
    answer.push_back(plan);
    while(!left_homework.empty()){
        answer.push_back(left_homework.back().first);
        left_homework.pop_back();
    }
    return answer;
}