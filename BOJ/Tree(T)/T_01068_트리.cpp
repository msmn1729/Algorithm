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

int n, eraseNode;
vector<int> childInfo[51];
int ans;

void countLeafNode(int cur) {
    if(childInfo[cur].empty()) {
        ans++;
        return;
    }
    
    // 자식이 하나이면서 자식이 삭제할 노드인 경우
    if(childInfo[cur].size() == 1 && eraseNode == childInfo[cur][0]) {
        ans++;
        return;
    }
    
    for(auto childNode : childInfo[cur]) {
        if(childNode == eraseNode) continue;
        countLeafNode(childNode);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    int root = 0;
    for(int i=0; i<n; i++) {
        int parent;
        cin >> parent;
        if(parent == -1) root = i;
        else childInfo[parent].push_back(i);
    }
    cin >> eraseNode;
    
    if(eraseNode == root) cout << 0;
    else {
        countLeafNode(root);
        cout << ans;
    }
    
    return 0;
}
