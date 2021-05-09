#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m) {
    if(m == 0) return n;
    return gcd(m, n%m);
}

int lcm(int n, int m, int gcd) {
    return n * m / gcd;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m, answer[0]));
    
    return answer;
}
