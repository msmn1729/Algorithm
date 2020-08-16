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
//
////치킨 배달
////https://www.acmicpc.net/problem/15686
////시간초과 다섯시간 소요 결국해냄!
////순열
//
//using namespace std;
//int n, m, x[100];
//int home_cnt=0, chicken_cnt=0, idx=0;
//vector<pair<int, int> > chicken_pos;
//vector<pair<int, int> > home_pos;
//vector<pair<int, int> > select_chicken_pos(100);
//vector<vector<pair<int, int> > > v;
//
//void DFS(int start, int depth)
//{
//    if(depth == m)
//    {
//        v.push_back(select_chicken_pos);
//    }
//    for(int i=start; i<chicken_pos.size(); i++)
//    {
//        select_chicken_pos[depth] = chicken_pos[i];
//        DFS(i+1, depth+1);
//    }
//}
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    int i, j, in, min_dif = 987654321, dif, sum=0, min_sum = 987654321;
//    cin >> n >> m;
//    for(i=0; i<n; i++)
//    {
//        for(j=0; j<n; j++)
//        {
//            cin >> in;
//            if(in == 2) chicken_pos.push_back({i, j});
//            else if(in == 1) home_pos.push_back({i, j});
//        }
//    }
//    DFS(0, 0);
//    for(int k=0; k<v.size(); k++)
//    {
//        sum = 0;
//        for(i=0; i<home_pos.size(); i++)
//        {
//            min_dif = 987654321;
//            for(j=0; j<m; j++)
//            {
//                dif = abs(home_pos[i].first - v[k][j].first)
//                + abs(home_pos[i].second - v[k][j].second);
//                min_dif = min(min_dif, dif);
//            }
//            sum += min_dif; //n번 집에서 가장 가까운 치킨집까지의 거리를 더해줌
//        }
//        min_sum = min(sum, min_sum);
//    }
//    cout << min_sum;
//}
