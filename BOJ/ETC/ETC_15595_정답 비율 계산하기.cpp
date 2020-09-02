#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << setprecision(16);
    int n, result_type, ans_cnt=0, attemp_cnt=0;
    map<string, int> m;

    cin >> n;
    string id, tmp;
    while(n--)
    {
        cin >> tmp >> id >> result_type;
        getline(cin, tmp);
        if(id.compare("megalusion")) //관리자가 아닐 때
        {
            if(m[id] != -1) //정답을 맞추기 전
            {
                if(result_type == 4) //정답
                {
                    ans_cnt++;
                    attemp_cnt += m[id]+1; //누적합
                    m[id] = -1;
                }
                else
                {
                    m[id]++;
                }
            }
        }
    }
    if(attemp_cnt == 0) cout << 0;
    else cout << (double)ans_cnt/attemp_cnt*100;
}
