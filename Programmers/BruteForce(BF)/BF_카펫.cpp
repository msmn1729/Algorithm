#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    
    for(int w=ceil(sqrt(sum)); w<=brown/2; w++) {
        int h = sum / w;
        int cnt_brown = w*2 + (h-2)*2;
        int cnt_yellow = sum - cnt_brown;
        if(cnt_brown == brown && cnt_yellow == yellow) {
            answer.push_back(w);
            answer.push_back(sum / w);
            break;
        }
    }
    return answer;
}
