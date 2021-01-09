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
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/18111 마인크래프트

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, b, i, j;
    int ar[501][501] = {};
    cin >> n >> m >> b;
    
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            cin >> ar[i][j];
        }
    }
    
    int min_time = 2e9, max_height = -2e9;
    for(int height=256; height>=0; height--) {
        int sum_time = 0, cnt_b = b;
        
        for(i=0; i<n; i++) {
            for(j=0; j<m; j++) {
                //인벤토리에서 꺼내서 쌓는 경우
                if(height - ar[i][j] > 0) {
                    cnt_b -= (height - ar[i][j]);
                    sum_time += (height - ar[i][j]);
                }
                //좌표의 블록을 빼서 인벤토리에 넣는 경우
                else if(height - ar[i][j] < 0){
                    cnt_b += (ar[i][j] - height);
                    sum_time += (ar[i][j] - height)*2;
                }
            }
        }
        
        //인벤토리가 음수가 아니면서 이전보다 소요시간이 적을 때
        if(cnt_b >= 0 && min_time > sum_time) {
            min_time = sum_time;
            max_height = height;
        }
    }
    cout << min_time << ' ' << max_height;
    
    return 0;
}
