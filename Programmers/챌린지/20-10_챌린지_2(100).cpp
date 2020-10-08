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
//#include <cstring>
//#include <cmath>
//#include <set>
//#include <bitset>
//
//using namespace std;
//
//vector<int> ans(2, 0);
//
//void dfs(const vector<vector<int>> &ar, int x, int y, int size)
//{
//    if (size == 1)
//    {
//        ans[ar[x][y]]++;
//        return;
//    }
//
//    int chk_num = ar[x][y];
//    bool flag = false;
//
//    for (int i = x; i < x + size; i++)
//    {
//        for (int j = y; j < y + size; j++)
//        {
//            if(chk_num != ar[i][j])
//            {
//                flag = true;
//                break;
//            }
//        }
//        if(flag) break;
//    }
//
//    if(!flag) //병합 가능하면 답에 추가하고 아래 재귀는 돌지 않음
//    {
//        ans[ar[x][y]]++;
//        return;
//    }
//
//    size /= 2;
//    dfs(ar, x, y, size);
//    dfs(ar, x, y + size, size);
//    dfs(ar, x + size, y, size);
//    dfs(ar, x + size, y + size, size);
//}
//
//vector<int> solution(vector<vector<int>> ar)
//{
//    dfs(ar, 0, 0, (int)ar.size());
//    return ans;
//}
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    solution({{1,1,0,0}, {1,0,0,0}, {1,0,0,1}, {1,1,1,1}});
////    dfs({{1,1,0,0}, {1,0,0,0}, {1,0,0,1}, {1,1,1,1}}, 0, 0, 4);
//    cout << '\n' << ans[0] << ' ' << ans[1] << '\n';
//    return 0;
//}
//
////**********************************************************************
//
//
////
////using namespace std;
////
////vector<int> answer(2, 0);
////
////void QuadTree(const vector<vector<int>>& arr, int beginX, int beginY, int size)
////{
////    if(size == 1)
////    {
////        answer[arr[beginY][beginX]]++;
////        return;
////    }
////
////    int CheckData = arr[beginY][beginX];
////    bool isCombinable = true;
////    // 다 똑같은지 검사.
////    for(int y=beginY; y<beginY+size; ++y)
////    {
////        for(int x=beginX; x<beginX+size; ++x)
////        {
////            // 병합 불가.
////            if(CheckData != arr[y][x])
////            {
////                isCombinable = false;
////                break;
////            }
////        }
////        if(!isCombinable) break;
////    }
////
////    // 병합 가능하면. 병합한것 추가.
////    if(isCombinable)
////    {
////        answer[CheckData]++;
////        return;
////    }
////
////    // 병합 불가시, 4등분.
////    int halfSize = (int)(size * 0.5f);
////    QuadTree(arr, beginX, beginY, halfSize);
////    QuadTree(arr, beginX + halfSize, beginY, halfSize);
////    QuadTree(arr, beginX, beginY + halfSize, halfSize);
////    QuadTree(arr, beginX + halfSize, beginY + halfSize, halfSize);
////}
////
////vector<int> solution(vector<vector<int>> arr) {
////    QuadTree(arr, 0 ,0, (int)arr.size());
////    cout << answer[0] << ' ' << answer[1];
////    return answer;
////}
////
////int main()
////{
////    ios::sync_with_stdio(0);
////    cin.tie(0);
////    cout.tie(0);
////
////    solution({{1,1,0,0}, {1,0,0,0}, {1,0,0,1}, {1,1,1,1}});
//////    dfs({{1,1,0,0}, {1,0,0,0}, {1,0,0,1}, {1,1,1,1}}, 0, 0, 4);
//////    cout << '\n' << ans[0] << ' ' << ans[1] << '\n';
////    return 0;
////}
