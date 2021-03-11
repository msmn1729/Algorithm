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

//https://www.acmicpc.net/problem/1021 회전하는 큐

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    deque<int> dq;
    int n, m;
    cin >> n >> m;
    
    for(int i=1; i<=n; i++) dq.push_back(i);
    
    int ans = 0;
    while(m--) {
        int in;
        cin >> in;
        
        int idx = 0; //찾는 숫자의 인덱스찾기
        for(int i=0; i<dq.size(); i++) {
            if(in == dq[i]) {
                idx = i;
                break;
            }
        }
        
        //왼쪽으로 이동
        if(idx <= dq.size() / 2) {
            for(int i=0; i<dq.size(); i++) {
                int front = dq.front();
                if(front == in) {
                    dq.pop_front();
                    ans += i;
                    break;
                }
                dq.pop_front();
                dq.push_back(front);
            }
            
        }
        //오른쪽으로 이동
        else {
            for(int i=0; i<dq.size(); i++) {
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
                if(dq.front() == in) {
                    dq.pop_front();
                    ans += i + 1;
                    break;
                }
            }
        }
    }
    cout << ans;
    
    return 0;
}
