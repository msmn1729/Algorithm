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
//using namespace std;
//
////https://www.acmicpc.net/problem/1629 좋은 수열
////풀어보니 쉬우나 처음부터 풀기는 쉽지않음
//
//int n;
//string seq;
//
//void make_seq(string seq)
//{
//    int len = (int)seq.length();
//    
//    for(int i=0; i<len/2; i++)
//    {
//        string b = seq.substr(len - i - 1 - (i + 1) , i+1); //앞부분
//        string a = seq.substr(len - i - 1, i+1); //뒷부분
//        //나쁜 수열
//        if(a == b) return;
//    }
//    if(seq.length() == n)
//    {
//        cout << seq << '\n';
//        exit(0);
//    }
//    
//    for(int i=0; i<3; i++)
//    {
//        make_seq(seq + (char)('1'+i));
//    }
//}
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    
//    cin >> n;
//    make_seq("1");
//}
