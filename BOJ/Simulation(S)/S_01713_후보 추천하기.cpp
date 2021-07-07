#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> photo;
    int visit[101] = {};
    int n, num_cc;
    cin >> n >> num_cc;
    
    for(int i=0; i<num_cc; i++) {
        int ord_cc;
        cin >> ord_cc;
        auto it = find(photo.begin(), photo.end(), ord_cc);
        
        // 사진틀에 없는 경우
        if(it == photo.end()) {
            // 사진 틀에 없고 사이즈가 남아있는 경우 바로 추가
            if(photo.size() < n) {
                visit[ord_cc]++;
                photo.push_back(ord_cc);
                continue;
            }
            // 지울 학생을 찾아야함
            int mn = 2e9;
            for(int j=0; j<photo.size(); j++) {
                mn = min(mn, visit[photo[j]]); // 가장 작은 추천수 찾기
            }
            int target = 0;
            for(int j=0; j<photo.size(); j++) {
                if(mn == visit[photo[j]]) {
                    target = photo[j]; // 가장 작은 추천수를 가진 오래된 학생 찾기
                    visit[target] = 0; // 학생 카운트 초기화
                    photo.erase(photo.begin() + j);
                    break;
                }
            }
            photo.push_back(ord_cc); // 새로운 학생 추가
        }
        visit[ord_cc]++;
    }
    sort(photo.begin(), photo.end());
    for(int it : photo) cout << it << ' ';
    
    return 0;
}
