#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#define ll long long
using namespace std;

string solution(int n) {
    string answer = "";
    
    while(n) {
        answer += "124"[(n-1) % 3];
        n = (n-1) / 3;
    }
    reverse(answer.begin(), answer.end());
    
    return answer;
}

int main() {
    for(int i=1; i<=10; i++) {
        cout << i << " : " << solution(i) << '\n';
    }
    
    return 0;
}
