#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int pos = 1;
    int idx = 0;
    
    while(pos <= n) {
        if(idx < stations.size() && stations[idx] - w <= pos) {
            pos = stations[idx] + w + 1;
            idx++;
            continue;
        }
        pos += 2*w + 1;
        answer++;
    }

    return answer;
}