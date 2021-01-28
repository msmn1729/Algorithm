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

//https://www.acmicpc.net/problem/5639 이진 검색 트리

vector<pair<int, int> > v(1e6);

void dfs(int root) {
    if(root == 0) return;
    dfs(v[root].first);
    dfs(v[root].second);
    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int root, n;
    cin >> root;
    
    while(cin >> n) {
        int node = root;
        while(1) {
            if(node > n) {
                if(v[node].first == 0) {
                    v[node].first = n;
                    break;
                }
                else node = v[node].first;
            }
            else {
                if(v[node].second == 0) {
                    v[node].second = n;
                    break;
                }
                else node = v[node].second;
            }
        }
    }
    dfs(root);
    
    return 0;
}
