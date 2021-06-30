#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<double, int> &a, pair<double, int> &b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

vector<int> solution(int n, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int> > failure_rate;
    vector<int> v(n+2);
    int remain = stages.size();
    
    for(int a: stages) v[a]++;
    for(int i=1; i<=n; i++) {
        if(v[i] == 0) failure_rate.push_back({0, i});
        else failure_rate.push_back({(double)v[i] / remain, i});
        remain -= v[i];
    }
    sort(failure_rate.begin(), failure_rate.end(), cmp);
    for(auto it: failure_rate) answer.push_back(it.second);
        
    return answer;
}