#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> v;
    
    while(n) {
        v.push_back(n%10);
        n /= 10;
    }
    
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    
    for(int i=0; i<v.size(); i++) {
        answer += v[i];
        answer *= 10;
    }
    answer /= 10;
    
    return answer;
}
