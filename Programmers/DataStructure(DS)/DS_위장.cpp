#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    int len = clothes.size();
    unordered_map<string, int> m;
    
    for(int i=0; i<len; i++) {
        m[clothes[i][1]]++;
    }
    
    for(auto it: m) {
        answer *= it.second + 1;
    }
    
    return answer - 1;
}
