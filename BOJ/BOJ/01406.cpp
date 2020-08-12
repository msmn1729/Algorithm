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
//int main(int argc, const char * argv[]) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cout << setprecision(16);
//    
//    int n;
//    string s;
//    char oper, c;
//    cin >> s >> n;
//    
//    list<char> l;
//    for(int i=0; i<s.length(); i++)
//    {
//        l.push_back(s[i]); //리스트에 문자열 삽입
//    }
//    list<char>::iterator pos = l.end(); //커서는 마지막
//    
//    while(n--)
//    {
//        cin >> oper;
//        if(oper == 'P')
//        {
//            cin >> c;
//            l.insert(pos, c);
//        }
//        else if(oper == 'L')
//        {
//            if(pos != l.begin()) pos--;
//        }
//        else if(oper == 'D')
//        {
//            if(pos != l.end()) pos++;
//        }
//        else if(oper == 'B')
//        {
//            if(pos != l.begin())
//            {
////                pos--;
//                pos = l.erase(--pos); //꼭 이 방법뿐?
////                pos++;
//            }
//        }
//        
//    }
//    for(auto i=l.begin(); i!=l.end(); i++){
//        cout << *i;
//    }
//}
