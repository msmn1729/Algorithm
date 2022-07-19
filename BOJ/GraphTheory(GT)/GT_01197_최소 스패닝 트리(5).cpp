#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

int parent[10101];

struct info {
    int st, ed, cost;
};

bool compare(info a, info b) {
    return a.cost < b.cost;
}

// 부모 노드를 찾음
int find(int a) {
    if(a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return; // 부모가 같으면 병합하지 않음
    if(a < b) parent[b] = a;
    else parent[a] = b;
}


int main() {
    int vertexCnt, edgeCnt, ans = 0;;
    cin >> vertexCnt >> edgeCnt;
    
    vector<info> v;
    
    int st, ed, cost;
    while(edgeCnt--) {
        cin >> st >> ed >> cost;
        v.push_back({st, ed, cost});
    }
    
    // 크루스칼
    // 1. 비용 오름차순으로 정렬
    sort(v.begin(), v.end(), compare);
    
    
    // 2. 사이클이 생기지 않도록 유니온 파인드로 체크하면서 MST 생성
    for(int i=1; i<=vertexCnt; i++) parent[i] = i;
    
    for(auto it : v) {
        if(find(it.st) == find(it.ed)) continue;
        merge(it.st, it.ed);
        ans += it.cost;
    }
    
    cout << ans;

    return 0;
}
