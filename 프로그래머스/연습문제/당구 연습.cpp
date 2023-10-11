#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>

using namespace std;
int cal_dis(int m, int n, int sx, int sy, int bx, int by){
    vector<int> tmp;
    if(!(sx == bx && sy < by)){
        int dis = pow(abs(sx-bx), 2) + pow((n-sy+n-by), 2);
        tmp.push_back(dis);
    }
    if(!(sx == bx && sy > by)){
        int dis = pow(abs(sx-bx), 2) + pow((sy+by), 2);
        tmp.push_back(dis);
    }
    if(!(sx < bx && sy == by)){
        int dis = pow(abs(sy-by), 2) + pow((m-sx+m-bx), 2);
        tmp.push_back(dis);
    }
    if(!(sx > bx && sy == by)){
        int dis = pow(abs(sy-by), 2) + pow((sx+bx), 2);
        tmp.push_back(dis);
    }
    return *min_element(tmp.begin(), tmp.end());
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    for(auto ball : balls){
        answer.push_back(cal_dis(m, n, startX, startY, ball[0], ball[1]));
    }
    return answer;
}