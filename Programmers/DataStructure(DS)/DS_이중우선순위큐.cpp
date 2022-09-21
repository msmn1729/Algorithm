#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#define ll long long
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq_desc;
    priority_queue<int, vector<int>, greater<>> pq_asc;
    int size = 0;
    
    for(string op : operations) {
        stringstream ss(op);
        string s;
        int num;
        ss >> s;
        ss >> num;
        
        if(s == "I") {
            pq_desc.push(num);
            pq_asc.push(num);
            size++;
        }
        else if(s == "D" && num == 1) {
            if(!size) continue;
            pq_desc.pop();
            size--;
        }
        else if(s == "D" && num == -1) {
            if(!size) continue;
            pq_asc.pop();
            size--;
        }
        
        if(!size) {
            pq_desc = priority_queue<int>();
            pq_asc = priority_queue<int, vector<int>, greater<>>();
        }
    }
    if(!size) return {0, 0};
    cout << pq_desc.top() << ' ' << pq_asc.top();
    answer.push_back(pq_desc.top());
    answer.push_back(pq_asc.top());
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
//    solution({"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"});
//    solution({"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"});
    solution({"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "I 5", "I 6"}); // {6, 5}
    
    return 0;
}
