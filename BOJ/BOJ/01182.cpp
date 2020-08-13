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
//#define MAX_SIZE 20
//int num[MAX_SIZE];
//int combi[MAX_SIZE];
//int n, s, sum, ans;
//
//using namespace std;
//
//void DFS(int start, int depth)
//{
//    if(depth > 0) //깊이가 존재하면
//    {
//        for(int i=0; i<depth; i++)
//        {
//            cout << combi[i] << ' ';
//            sum += combi[i];
//        }
//        if(sum == s) ans++;
//        sum = 0;
//        cout << '\n';
//    }
//    for(int i=start; i<n; i++)
//    {
//        combi[depth] = num[i];
//        DFS(i+1, depth+1);
//    }
//}
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cout << setprecision(16);
//
//    int i;
//    cin >> n >> s;
//    for(i=0; i<n; i++)
//    {
//        cin >> num[i];
//    }
//    DFS(0, 0);
//    cout << ans;
//}
