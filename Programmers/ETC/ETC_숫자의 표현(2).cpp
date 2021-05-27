#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int st = 0, ed = 1, sum = 1;
    
    while(st < n) {
        if(sum == n) ++answer;
        if(sum <= n) sum += ++ed;
        else sum -= ++st;
    }
    
    return answer;
}