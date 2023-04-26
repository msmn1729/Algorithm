#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <map>
#include <queue>
#define ll long long
#define INF 1e9
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int len = (int)p.size();
    
    for(int i=0; i<=t.size()-len; i++) {
        ll tokNum = stoll(t.substr(i, len));
        if(tokNum <= stoll(p)) answer++;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution("3141592", "271");

    return 0;
}

