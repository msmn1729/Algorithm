#include <bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;

int solution(string s) {
    int answer = 0;
    
    int cnt = 0, otherCnt = 0;
    char target = s[0];
    vector<string> v;
    string subStr = "";
    
    for(int i=0; i<s.size(); i++) {
        subStr += s[i];
        if(target == s[i]) {
            cnt++;
        }
        else {
            otherCnt++;
        }
        if(cnt == otherCnt) {
            cnt = otherCnt = 0;
            if(i == s.size()-1) continue;
            target = s[i+1];
            v.push_back(subStr);
            subStr = "";
        }
    }
    
    v.push_back(subStr);
    answer = v.size();
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}

