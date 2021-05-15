#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> us;

    char prev = words[0].front();
    
    for(int i=0; i<words.size(); i++) {
        int man_idx = (i % n) + 1;
        
        if(us.find(words[i]) != us.end()) {
            answer.push_back(man_idx);
            answer.push_back((i / n) + 1);
            return answer;
        }
        us.insert(words[i]);
        
        if(prev != words[i].front()) {
            answer.push_back(man_idx);
            answer.push_back((i / n) + 1);
            return answer;
        }
        prev = words[i].back();
    }
    
    answer.push_back(0);
    answer.push_back(0);
    
    return answer;
}
