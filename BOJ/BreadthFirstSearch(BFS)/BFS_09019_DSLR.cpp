#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/9019 DSLR

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n, target;
    cin >> t;
    
    while(t--) {
        cin >> n >> target;
        bool visit[10000] = {};
        queue<pair<int, string> > q;
        q.push({n, ""});
        visit[n] = true;
        
        while(!q.empty()) {
            int cur_num = q.front().first;
            string cur_oper = q.front().second;
            int nxt_num;
            q.pop();
            
            if(cur_num == target) {
                cout << cur_oper << '\n';
                break;
            }
        
            //D
            nxt_num = (cur_num * 2) % 10000;
            if(!visit[nxt_num]) {
                visit[nxt_num] = true;
                q.push({nxt_num, cur_oper + 'D'});
            }
            
            //S
            nxt_num = (cur_num + 9999) % 10000;
            if(!visit[nxt_num]) {
                visit[nxt_num] = true;
                q.push({nxt_num, cur_oper + 'S'});
            }
            
            if(cur_num == 0) continue;
            //L
            int thousand = 1000;
            nxt_num = (cur_num%thousand)*10 + cur_num/thousand;
            
            if(!visit[nxt_num]) {
                visit[nxt_num] = true;
                q.push({nxt_num, cur_oper + 'L'});
            }
            
            //R
            nxt_num = cur_num/10 + thousand*(cur_num%10);
            if(!visit[nxt_num]) {
                visit[nxt_num] = true;
                q.push({nxt_num, cur_oper + 'R'});
            }
        }
    }
    return 0;
}
