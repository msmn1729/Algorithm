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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sum = 0;
    for(int i=0; i<5; i++) {
        int num;
        cin >> num;
        sum += num;
    }
    cout << sum;
    
    return 0;
}
