#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    string num[10] = {"zero", "one", "two", "three", "four",
                      "five", "six", "seven", "eight", "nine"};
    // 1. regex_replace
    for(int i=0; i<10; i++) s = regex_replace(s, regex(num[i]), to_string(i));
    
    // 2. replace
    // for(int i=0; i<10; i++) {
    //     while(s.find(num[i]) != string::npos) s.replace(s.find(num[i]), num[i].size(), to_string(i));
    // }
        
    return stoi(s);
}