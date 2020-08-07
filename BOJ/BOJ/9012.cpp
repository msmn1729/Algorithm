//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#include <queue>
//#include <string>
//#include <map>
//#include <iomanip>
//#include <list>
//
//using namespace std;
//
//queue<int> q;
//
//int main(int argc, const char * argv[]) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cout << setprecision(16);
//    
//    int n, i;
//    string s;
//    cin >> n;
//    while(n--)
//    {
//        cin >> s;
//        for(i=0; i<s.length(); i++)
//        {
//            if(s[i] == '(') q.push(s[i]);
//            else if(s[i] == ')')
//            {
//                if(q.empty() == true)
//                {
//                    break;
//                }
//                else
//                {
//                    q.pop();
//                }
//            }
//        }
//        if(i == s.length() && q.empty() == true)
//        {
//            cout << "YES" << '\n';
//        }
//        else
//        {
//            cout << "NO" << '\n';
//        }
//        queue<int> empty;
//        swap(q, empty);
//    }
//
//}
