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

vector<int> tree[11];
vector<int> v;
int k;

void insertTree(int depth, int st, int ed) {
    if(depth == k) return;
    int mid = (st+ed) / 2;
    int root = v[mid];
    tree[depth].push_back(root);
    
    insertTree(depth+1, st, mid-1); // 좌측 서브트리
    insertTree(depth+1, mid+1, ed); // 우측 서브트리
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> k;
    for(int i=0; i<pow(2, k)-1; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    insertTree(0, 0, (int)v.size()-1);
    
    for(int i=0; i<k; i++) {
        for(int val : tree[i]) {
            cout << val << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
