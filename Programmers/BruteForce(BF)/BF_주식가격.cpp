#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int len = prices.size();
    
    for(int i=0; i<len; i++) {
        int cnt = 0;
        for(int j=i+1; j<len; j++) {
            if(prices[i] <= prices[j]) cnt++;
            else {
                cnt++;
                break;
            }
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
