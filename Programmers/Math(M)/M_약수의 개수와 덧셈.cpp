#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    
    for(int i=left; i<=right; i++) {
        if((int)sqrt(i)*sqrt(i) == i) answer -= i;
        else answer += i;
    }
    
    return answer;
}