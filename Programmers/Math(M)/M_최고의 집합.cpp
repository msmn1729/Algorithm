#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stack>
#include <unordered_map>
#include <set>
#define ll long long
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s) return {-1};
    
    int quotient = s/n;
    int remainder = s%n;
    
    for(int i=0; i<n; i++) {
        answer.push_back(quotient);
    }
    
    for(int i=0; i<remainder; i++) {
        answer[(n-1)-i]++;
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    return 0;
}
