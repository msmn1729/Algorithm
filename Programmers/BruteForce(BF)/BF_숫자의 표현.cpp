#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum[10001] = {0, 1};
    
    for(int i=1; i<=n; i++) {
        sum[i] = sum[i-1] + i;
        if(sum[i] == n) answer++;
        if(sum[i] <= n) continue;
        
        for(int j=i-1; j>=1; j--) {
            if(sum[i] - sum[j] > n) break;
            if(sum[i] - sum[j] == n) {
                answer++;
                break;
            }
        }
    }
    
    return answer;
}
