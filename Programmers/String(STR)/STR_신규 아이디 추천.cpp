#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    string id[8] = {};
    // 1
    for(auto c: new_id) id[1] += tolower(c);
    
    // 2
    string id2_filter = "-_.";
    for(auto c: id[1]) {
        if(isdigit(c) || isalpha(c)
           || find(id2_filter.begin(), id2_filter.end(), c) != id2_filter.end()) id[2] += c;
    }
    
    // 3
    for(auto c: id[2]) {
        if(c == '.' && id[3].size() && id[3].back() == '.') continue;
        id[3] += c;
    }
    
    // 4
    for(int i=0; i<id[3].size(); i++) {
        if(i == 0 && id[3][i] == '.') continue;
        if(i == id[3].size() - 1 && id[3][i] == '.') continue;
        id[4] += id[3][i];
    }
    
    // 5
    id[5] = id[4];
    if(id[4].empty()) id[5] = "a";
    
    // 6
    id[6] = id[5].substr(0, 15);
    if(id[6].back() == '.') id[6].pop_back();
    
    // 7
    id[7] = id[6];
    while(id[7].size() <= 2) {
        id[7] += id[7].back();
    }
    
    answer = id[7];
    
    return answer;
}
