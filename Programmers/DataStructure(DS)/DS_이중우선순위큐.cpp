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
#include <set>
#define ll long long
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    
    for(string op : operations) {
        stringstream ss(op);
        string s;
        int num;
        ss >> s;
        ss >> num;
        
        if(s == "I") {
            ms.insert(num);
        }
        else if(s == "D" && num == 1) {
            if(ms.empty()) continue;
            ms.erase(--ms.end());
        }
        else if(s == "D" && num == -1) {
            if(ms.empty()) continue;
            ms.erase(ms.begin());
        }
    }
    if(ms.empty()) answer = {0, 0};
    else answer = {*(--ms.end()), *ms.begin()};
    
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
