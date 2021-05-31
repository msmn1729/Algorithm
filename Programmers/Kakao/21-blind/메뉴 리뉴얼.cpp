#include <string>
#include <vector>
#include <iostream>
#include <map> 
#include <algorithm>

using namespace std;

map<string, int> freq[11];
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for(auto order: orders) {
        sort(order.begin(), order.end());
        for(int i=0; i < (1 << order.size()); i++) {
            string menu;
            for(int j=0; j<order.size(); j++) {
                if(i & (1 << j)) menu += order[j];
            }
            freq[menu.size()][menu]++;
        }
    }
    
    for(auto a : course) {
        int mx = 0;
        for(auto it : freq[a]) {
            mx = max(mx, it.second);
        }
        if(mx < 2) continue;
        for(auto it : freq[a]) {
            if(mx == it.second) {
                cout << it.first << ' ' << it.second << '\n';
                answer.push_back(it.first);
            }
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}