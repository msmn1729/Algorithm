#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
    int T, test_case;
    int N, K;
    int i, in;
    vector<int> A_menu, B_menu;
    
    cin >> T;
    for(test_case = 0; test_case  < T; test_case++)
    {
        int sum = 0, mx = 0;
        Answer = 0;
        cin >> N >> K;
        for(i=0; i<N; i++)
        {
            cin >> in;
            A_menu.push_back(in);
        }
        for(i=0; i<N; i++)
        {
            cin >> in;
            B_menu.push_back(in);
        }
        
        sort(A_menu.begin(), A_menu.end());
        sort(B_menu.begin(), B_menu.end());
        
        for(i=0; i<K; i++)
        {
            sum = A_menu[i] + B_menu[K-i-1];
            mx = max(mx, sum);
        }
        //순열 시간초과
        //        do{
        //            mx = 0;
        //            for(i=0; i<K; i++)
        //            {
        //                sum = A_menu[i] + B_menu[i];
        //                mx = max(mx, sum);
        //            }
        //            mn = min(mn, mx);
        //                }while(next_permutation(A_menu.begin(), A_menu.begin()+K));
        //        Answer = mn;
        Answer = mx;
        cout << "Case #" << test_case+1 << '\n';
        cout << Answer << '\n';
        A_menu.clear();
        B_menu.clear();
    }
    
    return 0;
}
