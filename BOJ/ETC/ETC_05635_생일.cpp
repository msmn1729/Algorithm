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
#define INF 1e9
using namespace std;

typedef struct {
    string name;
    int day;
} info;

bool cmp(info a, info b) {
    return a.day < b.day;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<info> v(n);
    for(int i=0; i<n; i++) {
        int d, m, y;
        cin >> v[i].name >> d >> m >> y;
        v[i].day = d + m*30 + y*365;
    }
    sort(v.begin(), v.end(), cmp);
    cout << v.back().name << '\n' << v.front().name;

    return 0;
}
