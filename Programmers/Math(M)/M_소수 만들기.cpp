#include <vector>
#include <iostream>
using namespace std;

int prime[3001];

int solution(vector<int> nums) {
    int answer = 0;
    int len = nums.size();
    
    for(int i=2; i<=3000; i++) {
        if(prime[i]) continue;
        for(int j=i+i; j<=3000; j+=i) {
            prime[j] = 1;
        }
    }
    
    for(int i=0; i<len; i++) {
        for(int j=i+1; j<len; j++) {
            for(int k=j+1; k<len; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                if(!prime[sum]) answer++;
            }
        }
    }

    return answer;
}
