#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

int ar[10];
int visit[10];
int numbersSize;
int combi[10];
int ans = 0;
set<int> s;

bool primeCheck(int n) {
    for(int i=2; i*i<=n; i++) {
        if(n%i == 0) return false;
    }
    return true;
}

void go(int start, int depth, int cnt) {
    if(depth == cnt) {
        int newNum = 0;
        for(int i=0; i<depth; i++) {
            newNum *= 10;
            newNum += combi[i];
        }
        s.insert(newNum);
        return;
    }
    for(int i=0; i<numbersSize; i++) {
        if(visit[i]) continue;
        combi[depth] = ar[i];
        visit[i] = 1;
        go(i+1, depth+1, cnt);
        visit[i] = 0;
    }
}

int solution(string numbers) {
    numbersSize = (int)numbers.size();
    for(int i=0; i<numbersSize; i++) {
        ar[i] = numbers[i] - '0';
    }
    for(int i=1; i<=numbersSize; i++) {
        go(0, 0, i);
    }
    
    for(auto it=s.begin(); it!=s.end(); it++) {
        cout << *it << '\n';
        if(*it < 2) continue;
        ans += primeCheck(*it);
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cout << solution("17");
    
    return 0;
}
