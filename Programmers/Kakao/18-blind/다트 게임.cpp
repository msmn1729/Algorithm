#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int num = 0;
    vector<int> v;
    
    for(char c : dartResult) {
        if(isdigit(c)) num = num * 10 + c -'0';
        else {
            if(c == 'S') {
                answer += num;
                v.push_back(num);
            }
            else if(c == 'D') {
                answer += num*num;
                v.push_back(num*num);
            }
            else if(c == 'T') {
                answer += num*num*num;
                v.push_back(num*num*num);
            }
            else if(c == '*') {
                answer += v.back() + v[v.size()-2];
                v.back() *= 2;
                v[v.size()-2] *= 2;
            }
            else if(c == '#') {
                answer -= v.back() * 2;
                v.back() *= -1;
            }
            num = 0;
        }
    }
    
    return answer;
}