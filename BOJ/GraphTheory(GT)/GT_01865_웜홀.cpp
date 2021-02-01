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
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/1865 웜홀

struct info {
    int start;
    int end;
    int weight;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n, m, w;
    int s, e, c;
    
    cin >> t;
    while(t--) {
        cin >> n >> m >> w;
        
        vector<int> dist(n+1, INF);
        dist[1] = 0;
        vector<info> v;
        for(int i=0; i<m; i++) {
            cin >> s >> e >> c;
            v.push_back({s, e, c});
            v.push_back({e, s, c});
        }
        for(int i=0; i<w; i++) {
            cin >> s >> e >> c;
            v.push_back({s, e, -c});
        }
        
        //최단 경로를 가질 수 있는 최대 크기(n-1) 만큼 반복
        for(int i=1; i<=n-1; i++) {
            //모든 간선에 대해 순회
            for(int j=0; j<v.size(); j++) {
                int start = v[j].start;
                int end = v[j].end;
                int weight = v[j].weight;
                
                //해당 정점이 아직 연결된 단계가 아니면 패스
                if(dist[start] == INF) continue;
                if(dist[end] > dist[start] + weight) {
                    dist[end] = dist[start] + weight;
                }
            }
        }
        
        bool flag = false;
        //Negative edge cost cycles 여부 확인
        for(int i=0; i<v.size(); i++) {
            int start = v[i].start;
            int end = v[i].end;
            int weight = v[i].weight;
            
            //해당 정점이 아직 연결된 단계가 아니면 패스
//            if(dist[start] == INF) continue; //이 부분있으면 틀림
            if(dist[end] > dist[start] + weight) { //음의 사이클 존재
                flag = true;
                break;
            }
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
