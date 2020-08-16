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
//#define MAX_SIZE 15
//int board[MAX_SIZE][MAX_SIZE];
//int visit[MAX_SIZE][MAX_SIZE];
//int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1};
//int dy[8] = {-1, 1, 0, 0, 1, -1, 1, -1};
//bool vis1[40];
//bool vis2[40];
//bool vis3[40];
//int n, ans;
//
//using namespace std;
//vector<string> V;
//
//void func(int cur)
//{
//    if(cur == n)
//    {
//        ans++;
//        return;
//    }
//    for(int i=0; i<n; i++)
//    {
//        if(vis1[i] || vis2[cur+i] || vis3[cur-i+n-1]) continue;
//        vis1[i] = true;
//        vis2[cur+i] = true;
//        vis3[cur-i+n-1] = true;
//        func(cur+1);
//        vis1[i] = false;
//        vis2[cur+i] = false;
//        vis3[cur-i+n-1] = false;
//    }
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    cin >> n;
//    func(0);
//    cout << ans;
//}
//
//#include <iostream>
//
//using namespace std;
//
//int N;
//int vis[15][3];
//int result = 0;
//
//void N_Queen(int i)
//{
//    if(i == N)
//    {
//        result++;
//        return;
//    }
//    for(int j=0; j<N; j++)
//    {
//        if(vis[j][0] || vis[j+i][1] || vis[i-j+N][2]) continue;
//        vis[j][0] = vis[j+i][1] = vis[i-j+N][2] = 1;
//        N_Queen(i+1);
//        vis[j][0] = vis[j+i][1] = vis[i-j+N][2] = 0;
//    }
//}
//
//int main()
//{
//    cin>>N;
//    N_Queen(0);
//    cout<<result<<endl;
//
//    return 0;
//}
