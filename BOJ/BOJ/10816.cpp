//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#include <queue>
//#include <string>
//#include <map>
//#include <iomanip>
//#include <list>
//
//using namespace std;
//
//vector<int> v;
//
//int main(int argc, const char * argv[]) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cout << setprecision(16);
//    
//    int n, m, in;
//    cin >> n;
//    while(n--)
//    {
//        cin >> in;
//        v.push_back(in);
//    }
//    sort(v.begin(), v.end());
//    cin >> m;
//    while(m--)
//    {
//        cin >> in;
//        auto lower = lower_bound(v.begin(), v.end(), in);
//        auto upper = upper_bound(v.begin(), v.end(), in);
//        cout << upper-lower << ' ';
//    }
//}
