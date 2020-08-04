//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <cstring>
//#include <queue>
//#include <string>
//#include <map>
//#include <iomanip>
//
//using namespace std;
//vector<int> v;
//
////이진 탐색 반환값은 찾은 인덱스
//int BinarySearch(int findData)
//{
//    int findIndex = -1, mid=0;
//    int start = 0;
//    int end = v.size()-1;
//    
//    while(start <= end) //시작인덱스가 끝인덱스보다 작은 동안 반복
//    {
//        mid = (start+end)/2; //중간 인덱스
//        if(findData > v[mid])
//        {
//            start = mid+1;
//
//        }
//        else if(findData < v[mid])
//        {
//            end = mid-1;
//        }
//        else
//        {
//            return 1;
//            //findIndex = mid;
//            break;
//        }
//    }
//    
//    return findIndex;
//}
//
//int main(int argc, const char * argv[]) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cout << setprecision(16);
//    
//    //vector<int> v;
//    int in, n, findData;
//    cin >> n;
//    while(n--)
//    {
//        cin >> in;
//        v.push_back(in);
//    }
//    sort(v.begin(), v.end());
//    
//    cin >> n;
//    while(n--)
//    {
//        cin >> findData;
//        if(BinarySearch(findData)>=0)
//        {
//            cout << 1;
//        }
//        else cout << 0;
//        cout << "\n";
//    }
//}
