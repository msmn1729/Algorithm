#include <bits/stdc++.h>
using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    // 1번 풀이
    // while(n >= a) {
    //     answer += (n/a)*b;
    //     n = n - (n/a)*a + (n/a)*b;
    // }
    
    // 2번 풀이 -> 가장 직관적
    while(n >= a) {
        n -= (a-b);
        answer += b;
    }
    
    // 3번 풀이 -> 2번 풀이 같은 로직 반복문 없이 계산
    // n -= a;
    // answer = (n/(a-b)+1) * b;
    
    return answer;
}
