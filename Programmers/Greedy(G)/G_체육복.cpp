#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(n+2);
    
    for(int i: lost) v[i]--;
    for(int i: reserve) v[i]++;
    
    for(int i=1; i<=n; i++) {
        if(v[i] >= 0) continue;
        if(v[i-1] > 0) {
            v[i]++;
            v[i-1]--;
        }
        else if(v[i+1] > 0) {
            v[i]++;
            v[i+1]--;
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(v[i] >= 0) answer++;
    }
    
    return answer;
}
