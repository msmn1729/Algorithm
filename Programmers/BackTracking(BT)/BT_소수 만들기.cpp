#include <vector>
#include <iostream>
using namespace std;

int answer;
int prime[3001];
vector<int> v;
int visit[51];

void go(int start, int depth, int sum) {
    if(depth == 3) {
        if(!prime[sum]) answer++;
        return;
    }
    for(int i=start; i<v.size(); i++) {
        if(visit[i]) continue;
        visit[i] = 1;
        go(i+1, depth+1, sum+v[i]);
        visit[i] = 0;
    }
}

int solution(vector<int> nums) {
    int len = nums.size();
    v = nums;
    
    for(int i=2; i<=3000; i++) {
        if(prime[i]) continue;
        for(int j=i+i; j<=3000; j+=i) {
            prime[j] = 1;
        }
    }
    
    go(0, 0, 0);

    return answer;
}
