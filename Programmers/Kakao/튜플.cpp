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

bool cmp(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int> > v;
    int idx = 0;
    int sum = 0;
    
    for(int i=0; i<s.size(); i++) {
        if(isdigit(s[i])) {
            sum *= 10;
            sum += s[i] - '0';
            continue;
        }
        if(sum && v.size() <= idx) v.push_back(vector<int>());
        if(s[i] == ',') {
            if(sum) v[idx].push_back(sum);
            sum = 0;
        }
        if(s[i] == '}') {
            if(sum) {
                v[idx].push_back(sum);
            }
            sum = 0;
            idx++;
        }
    }
    
    sort(v.begin(), v.end(), cmp);
    
    unordered_map<int, int> m;
    for(int i=0; i<v.size(); i++) {
        for(int j=0; j<v[i].size(); j++) {
            int num = v[i][j];
            if(!m[num]) answer.push_back(num);
            m[num] = 1;
        }
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution("{{1,2,3},{2,1},{1,2,4,3},{2}}");
    
    return 0;
}
