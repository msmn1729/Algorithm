#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    return stoi(a+b) > stoi(b+a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for(int i=0; i<numbers.size(); i++) {
        v.push_back(to_string(numbers[i]));
    }
    sort(v.begin(), v.end(), compare);
    
    if(v.front() == "0") return "0";
    for(auto it: v) answer += it;
    
    return answer;
}