#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0; i<numbers.size(); i++)
    {
        for(int j=i+1; j<numbers.size(); j++)
        {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(answer.begin(), answer.end());
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    //1
    vector<int> v;
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(1);
    
    vector<int> a = solution(v);
    for(int i : a)
    {
        cout << i << ' ';
    }
    
    return 0;
}
