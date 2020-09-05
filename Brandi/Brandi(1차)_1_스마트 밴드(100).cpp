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
//int main()
//{
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    
//    int n, in, ans[6]={};
//    double max_rate, rate;
//    cin >> n;
//    max_rate = 220-n;
//    while(cin >> in)
//    {
//        rate = in / max_rate * 100;
//        if(rate>=90) ans[0]++;
//        else if(rate>=80) ans[1]++;
//        else if(rate>=75) ans[2]++;
//        else if(rate>=68) ans[3]++;
//        else if(rate>=60) ans[4]++;
//        else ans[5]++;
//    }
//    for(int i : ans) cout << i << ' ';
//    
//    return 0;
//}
