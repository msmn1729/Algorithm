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

using namespace std;

stack<int> stk;
vector<char> v;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(16);

    int n, i, index=0;
    cin >> n;
    int num[n];
    for(i=0; i<n; i++)
    {
        cin >> num[i]; //num배열에 만들수열 순서대로 저장
    }
    for(i=1; i<=n; i++)
    {
        stk.push(i); //스택에 숫자 순서대로 푸쉬
        v.push_back('+'); //푸쉬할 때 연산자 + 푸쉬백
        while(stk.empty() == false && num[index] == stk.top())
        {
            stk.pop();
            v.push_back('-');
            index++;
        }
    }
    if(stk.empty() == false) cout << "NO";
    else for(auto it:v) cout << it << endl;
}

