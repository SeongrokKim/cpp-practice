#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    pair<int, int> result;
    int s = 0;
    int e = 0;
    int seqSize = sequence.size();
    int subLen = seqSize+1;
    int sum = sequence[0];
    while(s<=e && e<seqSize){
        if(sum < k){
            sum += sequence[++e];
        }
        else if(sum == k){
            if(e-s+1 < subLen){
                subLen = e-s+1;
                result = {s, e};
            }
            else if(e-s+1 == subLen){
                if(s < result.first){
                    result = {s, e};
                }
            }
            sum -= sequence[s++];
        }
        else{
            sum -= sequence[s++];
        }
    }
    answer.push_back(result.first);
    answer.push_back(result.second);
    return answer;
}