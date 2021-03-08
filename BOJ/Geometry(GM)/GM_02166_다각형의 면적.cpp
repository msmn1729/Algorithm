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
#include <iostream>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/2166 다각형의 면적

struct pos {
    double x, y;
};

vector<pos> vertex;

double area(int x1, int y1, int x2, int y2) {
    pos v1, v2;
    v1.x = vertex[0].x - x1; //벡터1
    v1.y = vertex[0].y - y1;
    v2.x = vertex[0].x - x2; //벡터2
    v2.y = vertex[0].y - y2;
    return v1.x * v2.y - v1.y * v2.x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    double ans = 0;
    cin >> n;
    for(int i=0; i<n; i++) {
        double x, y;
        cin >> x >> y;
        vertex.push_back({x, y});
    }
    
    for(int i=1; i<n-1; i++) ans += area(vertex[i].x, vertex[i].y, vertex[i+1].x, vertex[i+1].y);
    printf("%.1f", abs(ans) / 2.0);
    
    return 0;
}
