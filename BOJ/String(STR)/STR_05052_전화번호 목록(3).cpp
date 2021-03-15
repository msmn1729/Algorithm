#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <climits>
#include <cstring>
#include <iomanip>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>

#define ll long long
#define INF 1e9

using namespace std;

//https://www.acmicpc.net/problem/5052 전화번호 목록

struct Trie {
    Trie* next[10];
    bool finish;
    bool next_child;
    
    Trie() {
        finish = next_child = false;
        memset(next, 0, sizeof(next));
    }
    
    ~Trie() {
        for(int i=0; i<10; i++) {
            if(next[i]) delete next[i];
        }
    }
    
    // 문자열 key를 현재 노드부터 삽입 후 일관성 여부를 반환
    bool insert(const char* key) {
        if(*key == 0) {
            finish = true;
            if(next_child) return false;
            else return true;
        }
        if(finish) return false;
        int cur = *key - '0';
        if(next[cur] == NULL) next[cur] = new Trie();
        next_child = true;
        return next[cur]->insert(key + 1);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        Trie* root = new Trie;
        int flag = 0;
        char phone[11] = {};
        for(int i=0; i<n; i++) {
            cin >> phone;
            if(flag == 0 && root->insert(phone) == 0) flag = 1;
        }
        if(flag) cout << "NO";
        else cout << "YES";
        cout << '\n';
        delete root;
    }
    
    return 0;
}
