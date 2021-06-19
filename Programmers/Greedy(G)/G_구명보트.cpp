#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int idx = 0;
    sort(people.begin(), people.end());
    
    while(idx < people.size()) {
        int back = people.back();
        people.pop_back();
        if(people[idx] + back <= limit) idx++;
        answer++;
    }
    
    return answer;
}
