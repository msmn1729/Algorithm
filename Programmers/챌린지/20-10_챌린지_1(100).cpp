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
//int solution(int n)
//{
//    vector<int> v;
//    int ans = 0;
//    while(n)
//    {
//        v.push_back(n%3);
//        n/=3;
//    }
//    int tmp = 1;
//    reverse(v.begin(), v.end());
//    for(int it : v)
//    {
//        ans += it * tmp;
//        tmp *= 3;
//    }
//    cout << ans << '\n';
//    
//    return ans;
//}
//
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    
//    solution(45);
//    solution(125);
//
//    return 0;
//}
//
