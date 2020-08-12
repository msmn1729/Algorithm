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
//#define MAX_SIZE 13
//int lotto[MAX_SIZE]; //입력 배열
//int combi[MAX_SIZE];
//int k;
//
//using namespace std;
//
//list<int> l;
//vector<pair<int, int>> v;
//deque<int> dq;
//
//void DFS(int start, int depth)
//{
//    if(depth == 6) //깊이가 6이면 출력 후 탈출
//    {
//        for(int i=0; i<6; i++)
//        {
//            cout << combi[i] << ' ';
//        }
//        cout << '\n';
//    }
//    for(int i=start; i<k; i++)
//    {
//        combi[depth] = lotto[i];
//        DFS(i+1, depth+1);
//    }
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cout << setprecision(16);
//    
//    while(cin >> k && k)
//    {
//        for(int i=0; i<k; i++)
//        {
//            cin >> lotto[i];
//        }
//        DFS(0, 0);
//        cout << '\n';
//    }
//}
