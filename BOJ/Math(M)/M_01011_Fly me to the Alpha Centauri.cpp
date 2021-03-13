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

//https://www.acmicpc.net/problem/1011 Fly me to the Alpha Centauri

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    while(n--) {
        int x, y;
        cin >> x >> y;
        int dist = y - x;
        
        int max_speed = sqrt(dist);
        
        if(max_speed * max_speed == dist) { //삼각형 모양으로 쭉 올라갔다가 내려오는 형태
            cout << 2 * max_speed - 1;
        }
        else { //거리가 남는 형태
            if(dist - max_speed * max_speed <= max_speed) cout << 2 * max_speed;
            else cout << 2 * max_speed + 1;
        }
        cout << '\n';
    }
    
    return 0;
}
