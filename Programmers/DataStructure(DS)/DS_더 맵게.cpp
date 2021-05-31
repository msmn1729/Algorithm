#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> v, int k) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq(v.begin(), v.end());
    
    while(pq.top() < k) {
        if(pq.size() == 1) return -1;
        int first = pq.top();
        pq.pop();
        int new_scoville = first + pq.top()*2;
        pq.pop();
        pq.push(new_scoville);
        answer++;
    }
    return answer;
}