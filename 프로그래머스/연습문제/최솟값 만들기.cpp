#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
    if (a<b){
        return false;
    }
    return true;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(B.begin(), B.end(), compare);
    sort(A.begin(), A.end());
    for(int i=0;i<A.size();i++){
        answer += A[i]*B[i];
    }

    return answer;
}