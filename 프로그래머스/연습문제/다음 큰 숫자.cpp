#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string to_bin(int n){
    string bin = "";
    while(n>0){
        bin += to_string(n%2);
        n /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

int to_int(string bin){
    int n = 0;
    int t = 1;
    reverse(bin.begin(), bin.end());
    for(int i =0;i<bin.length();i++){
        int temp = bin[i] - '0';
        n += t*temp;
        t *= 2;
    }
    return n;
}

int solution(int n) {
    int answer = n+1;
    string n_bin = to_bin(n);
    while(true){
        string a_bin= to_bin(answer);
        if(count(n_bin.begin(), n_bin.end(), '1') == count(a_bin.begin(), a_bin.end(), '1')){
            break;
        }
        answer += 1;
    }
    return answer;
}