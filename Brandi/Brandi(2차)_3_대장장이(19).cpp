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
//
//using namespace std;
//
//
//int main(void)
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    int n, k, i, in, start, end;
//    int num[300002] = {};
//    long long dp[300002] = {};
//    cin >> n >> k;
//
//    for(i=1; i<=n; i++)
//    {
//        cin >> in;
//        num[i] = in;
//    }
//
//
//    for(i=0; i<k; i++)
//    {
//        cin >> start >> end;
//
//        fill(dp, dp+n+1, 0);
////        for(j=start; j<=end; j++)
////        {
////            int cnt = 0;
////            for(int l=start; l<=j; l++)
////            {
////                if(num[l] == num[j]) cnt++;
////            }
////            sum += num[j] * cnt;
////        }
//        dp[start] = num[start]; //처음 것만 저장
//        for(int a=start; a<=end; a++)
//        {
//            int cnt = 0;
//            for(int b=start; b<=a; b++)
//            {
//                if(num[a] == num[b]) cnt++;
//            }
//            dp[a] = dp[a-1] + num[a] * cnt;
//        }
//
////        for(int a=1; a<=n; a++) cout << dp[a] << ' ';
////        cout << "\n\n\n";
////        cout << dp[end] - dp[start] << '\n';
//        cout << dp[end] << '\n';
//    }
//
//    return 0;
//}
//
//
//
