#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int max_day = 0;
    for(int i=0; i<progresses.size(); i++) {
        int day = (99 - progresses[i]) / speeds[i] + 1;
        
        if(max_day < day) {
            answer.push_back(1);
            max_day = day;
        }
        else answer.back()++;
    }
    
    return answer;
}
