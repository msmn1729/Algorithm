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
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1002 터렛

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    int x1, y1, r1, x2, y2, r2;
    cin >> t;
    while(t--) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        //첫번째에 반지름이 더 작은 것으로 저장
        if(r2 < r1) {
            swap(x1, x2);
            swap(y1, y2);
            swap(r1, r2);
        }
        double dist = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));
        //1. 일치
        if(x1 == x2 && y1 == y2 && r1 == r2) cout << -1;
        //2. 멀리 떨어져있을 때
        else if(r1+r2 < dist) cout << 0;
        //3. 외접
        else if(r1+r2 == dist) cout << 1;
        //4. 두점
        else if(r1+r2 > dist && dist > r2-r1) cout << 2;
        //5. 내접
        else if(dist+r1 == r2) cout << 1;
        //6. 큰 원안에 작은 원이고 겹치지 않을 때
        else if(r2-r1 > dist) cout << 0;
        cout << '\n';
    }
    
    return 0;
}
