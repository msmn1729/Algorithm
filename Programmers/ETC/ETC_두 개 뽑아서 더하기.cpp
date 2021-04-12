#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> n) {
    vector<int> answer;
    set<int> s;
    
    int size = n.size();
    for(int i=0; i<size; i++) {
        for(int j=i+1; j<size; j++) {
            if(i == j) continue;
            int sum = n[i] + n[j];
            s.insert(sum);
        }
    }
    
    answer.assign(s.begin(), s.end());
    
    return answer;
}
