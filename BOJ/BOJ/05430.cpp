//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#include <queue>
//#include <string>
//#include <map>
//#include <iomanip>
//#include <list>
//#include <stack>
//#include <sstream>
//#include <stdlib.h>
//
//using namespace std;
//
//list<int> l;
//vector<pair<int, int>> v;
//deque<int> dq;
//
//int main(int argc, const char * argv[]) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cout << setprecision(16);
//    
//    int t,i, num_cnt=0, in, ten=1, sum=0, flag=0, num_flag=0;
//    int err_flag=0;
//    char* token, tmp;
//    
//    string func, ary;
//    cin >> t;
//    while(t--)
//    {
//        err_flag = 0, num_flag = 0, flag = 0;
//        cin >> func >> num_cnt >> ary;
//        istringstream iss(ary);
//        string token;
//        while(getline(iss, token, ','))
//        {
//            ten=1;
//            sum=0;
//            for(i=(int)token.length(); i>=0; i--)
//            {
//                if(isdigit(token[i]))
//                {
//                    num_flag = 1;
//                    sum += ten * (token[i]-'0');
//                    ten*=10;
//                }
//            }
//            if(num_flag) dq.push_back(sum); //데크에 저장
//        }
//        for(i=0; i<func.length(); i++)
//        {
////            flag = 0;
//            if(func[i] == 'R')
//            {
////                reverse(dq.begin(), dq.end()); //시간초과?
//                if(flag == 0) flag = 1;
//                else flag = 0;
//            }
//            else if(func[i] == 'D')
//            {
//                if(dq.empty())
//                {
//                    cout << "error" << '\n';
//                    err_flag=1;
//                    break;
//                }
//                else
//                {
//                    if(flag) dq.pop_back();
//                    else dq.pop_front();
//                }
//            }
//        }
//        if(err_flag) continue;
//        cout << '[';
//        if(!dq.empty())
//        {
//            if(flag)
//            {
//                cout << dq.back();
//                dq.pop_back();
//            }
//            else
//            {
//                cout << dq.front();
//                dq.pop_front();
//            }
//            while(!dq.empty())
//            {
//                if(flag)
//                {
//                    cout << ',' << dq.back();
//                    dq.pop_back();
//                }
//                else
//                {
//                    cout << ',' << dq.front();
//                    dq.pop_front();
//                }
//            }
//        }
//        cout << ']' << '\n';
//        dq.clear();
//    }
//}
