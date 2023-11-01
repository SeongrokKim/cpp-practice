#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    for(int i = 1; i<n+1; i++){
        int start = i;
        int sum = 0;
        while (sum<n){
            sum += start;
            start += 1;
        }
        if(sum == n){
            answer += 1;
        }
    }
    return answer;
}