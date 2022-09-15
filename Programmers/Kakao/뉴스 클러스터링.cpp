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
#define ll long long
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> m;
    vector<string> v1, v2;
    int intersection = 0;
    int sumOfSets = 0;
    
    for(int i=0; i<str1.size()-1; i++) {
        if(!isalpha(str1[i]) || !isalpha(str1[i+1])) continue;
        str1[i] = tolower(str1[i]);
        str1[i+1] = tolower(str1[i+1]);
        string s = str1.substr(i, 2);
        m[s]++;
        sumOfSets++;
    }
    
    for(int i=0; i<str2.size()-1; i++) {
        if(!isalpha(str2[i]) || !isalpha(str2[i+1])) continue;
        str2[i] = tolower(str2[i]);
        str2[i+1] = tolower(str2[i+1]);
        string s = str2.substr(i, 2);
        if(m[s] > 0) {
            m[s]--;
            intersection++;
        }
        else {
            sumOfSets++;
        }
    }
    if(sumOfSets == 0) return 65536;
    answer = ((double)intersection / sumOfSets) * 65536;
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cout << solution("di mi mi mi mi", "di di di go");

    return 0;
}
