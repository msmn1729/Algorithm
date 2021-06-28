#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#define ll long long

using namespace std;

unordered_map<ll, ll> parent;

ll find(ll n) {
    if(parent[n]) return parent[n] = find(parent[n]);
    return n;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<ll> answer;
    
    for(ll n: room_number) {
        ll root = find(n);
        answer.push_back(root);
        parent[root] = root + 1;
    }
    
    return answer;
}