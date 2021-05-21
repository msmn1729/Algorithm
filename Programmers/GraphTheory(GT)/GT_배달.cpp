#include <unordered_map>
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


int solution(int n, vector<vector<int> > road, int k) {
    int ar[51][51];
    int answer = 1;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            ar[i][j] = INF;
        }
    }
    
    for(int i=0; i<road.size(); i++) {
        int st = road[i][0];
        int ed = road[i][1];
        int cost = road[i][2];
        ar[st][ed] = ar[ed][st] = min(ar[st][ed], cost);
    }
    
    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(i == j) continue;
                ar[i][j] = min(ar[i][j], ar[i][k] + ar[k][j]);
            }
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(ar[1][i] <= k) answer++;
    }
    return answer;
}

int main() {
    
    solution(5, {{1,2,1}, {2,3,3}, {5,2,2}, {1,4,2}, {5,3,1}, {5,4,2}}, 3);
    
    return 0;
}
