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
//using namespace std;
//
//list<int> l;
//vector<pair<int, int>> v;
//
//int main(int argc, const char * argv[]) {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    cout << setprecision(16);
//    
//    int t, n, search_index=0, in, i, result=1;
//    cin >> t;
//    while(t--)
//    {
//        //큐 초기화
//        queue<pair<int, int>> q;
//        priority_queue<int> pq;
//        result = 1;
//        cin >> n >> search_index;
//        for(i=0; i<n; i++)
//        {
//            cin >> in;
//            q.push(make_pair(in, i)); //우선순위와 인덱스 저장
//            pq.push(in);
//            
//        }
//        while(!pq.empty())
//        {
//            if(pq.top() > q.front().first) //처음 원소 우선순위가 가장 높지 않을 때
//            {
//                q.push(q.front());//맨 뒤에 맨 앞 원소 삽입
//                q.pop(); //맨 앞 원소 삭제
//            }
//            else if(pq.top() == q.front().first) //큐의 맨 앞과 우선순위가 같을 때
//            {
//                if(search_index == q.front().second) //찾는 숫자의 인덱스와 같을 때
//                {
//                    cout << result << '\n'; //카운트 출력
//                    break;
//                }
//                result++;
//                pq.pop();
//                q.pop();
//            }
//        }
//    }
//}
