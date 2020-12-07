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

//https://www.acmicpc.net/problem/6679 싱기한 네자리 숫자

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for(int i=2992; i<1e4; i++) {
        int a = 0, b = 0, c = 0;
        int tmp = i;
        while(tmp) {
            a += tmp%12;
            tmp /= 12;
        }
        tmp = i;
        while(tmp) {
            b += tmp%16;
            tmp /= 16;
        }
        tmp = i;
        while(tmp) {
            c += tmp%10;
            tmp /= 10;
        }
        if(a == b && b == c) cout << i << '\n';
    }
    
    return 0;
}
