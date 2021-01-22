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

//https://www.acmicpc.net/problem/1107 리모컨

int broken[10] = {};

//숫자버튼만으로 만들 수 있다면 몇 번 눌러야하는지 반환
int countingMoveChannel(int channel) {
    if(channel == 0) return !broken[0];
    int cnt_btn = 0;
    while(channel) {
        if(broken[channel%10]) return 0;
        cnt_btn++;
        channel /= 10;
    }
    return cnt_btn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, i;
    cin >> n >> m;
    for(i=0; i<m; i++) {
        int in;
        cin >> in;
        broken[in] = 1;
    }
    
    int ans = abs(100-n);
    for(i=0; i<=1e6; i++) {
        int num_btn_cnt = countingMoveChannel(i);
        int PM_btn_cnt = abs(i-n);
        //숫자 버튼만으로 만들 수 있을 때
        if(num_btn_cnt) ans = min(ans, num_btn_cnt + PM_btn_cnt);
    }
    cout << ans;
    
    return 0;
}
