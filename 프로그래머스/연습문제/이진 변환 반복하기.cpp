#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int cnt = 0;
    int zeros = 0;
    while(s != "1"){
        while(s.find('0') != string::npos){
            s.erase(find(s.begin(), s.end(), '0'));
            zeros += 1;
        }
        int len = s.length();
        string new_s = "";
        while(len>0){
            new_s += to_string(len%2);
            len = len/2;
        }
        reverse(new_s.begin(), new_s.end());
        s = new_s;
        cnt += 1;
    }
    answer.push_back(cnt);
    answer.push_back(zeros);
    return answer;
}