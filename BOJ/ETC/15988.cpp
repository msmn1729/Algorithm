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
//#define MAX_SIZE 1000001
//int num[100];
//int combi[MAX_SIZE];
//long long result[MAX_SIZE];
//int n, s, sum, ans, cnt;
//
//using namespace std;
//vector<string> V;
//
//void DFS(int start, int depth)
//{
//    if(depth > 0) //합과 같으면서 깊이가 1이상인 경우
//    {
//        for(int i=0; i<depth; i++)
//        {
//            sum += combi[i];
//        }
//        if(sum == n)
//        {
//            char str[100] = {};
//            for(int i=0; i<depth; i++)
//            {
//                str[i] = combi[i] + '0';
//            }
//            V.push_back(str);
//            cnt++;
//
//        }
//        sum = 0;
//
//    }
//    for(int i=start; i<n; i++)
//    {
//        for(int j=1; j<=3; j++)
//        {
//            combi[depth] = j;
//            DFS(i+1, depth+1);
//        }
//    }
//}
//
//long long DP(long long n)
//{
//    if(n==0) return 0;
//    if(n==1) return 1;
//    if(n==2) return 2;
//    if(n==3) return 4;
//    return (DP(n-1)+DP(n-2)+DP(n-3)) % 1000000009;
//}
//
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cout << setprecision(16);
//
//    long long t, n;
//    cin >> t;
//    result[0] = 0;
//    result[1] = 1;
//    result[2] = 2;
//    result[3] = 4;
//    for(int i=4; i<1000001; i++)
//    {
//        result[i] = result[i-1] + result[i-2] + result[i-3];
//        result[i] %= 1000000009;
//    }
//    while(t--)
//    {
//        cin >> n;
//        printf("%lld\n", result[n]);
////        n %= 10000009;
////        printf("%d\n", DP(n));
//    }
//}
//
////#include<stdio.h>
////#include<algorithm>
////using namespace std;
////long long dp[1000001];
////int main() {
////
////    dp[1] = 1;
////    dp[2] = 2;
////    dp[3] = 4;
////
////    for(int i = 4; i <= 1000001; i++) {
////        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
////        dp[i] %= 1000000009;
////    }
////
////    int t;
////    scanf("%d",&t);
////    while(t--) {
////        int n;
////        scanf("%d",&n);
////        printf("%lld\n",dp[n]);
////    }
////    return 0;
////}
