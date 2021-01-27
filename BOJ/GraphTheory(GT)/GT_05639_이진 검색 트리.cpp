#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <map>
#include <iomanip>
#include <list>
#include <stack>
#include <cstring>
#include <cmath>
#include <set>
#include <unordered_map>
#include <bitset>
#define ll long long

using namespace std;

//https://www.acmicpc.net/problem/5639 이진 검색 트리

int tree[10002] = {};

void postOrder(int left, int right) {
    if(left > right) return;
    
    int root = left;
    int start = left, end = right;
    
    while(tree[root] <= tree[start]) start++;
    while(tree[root] < tree[end]) end--; //루트보다 큰 첫번째 값의 인덱스찾기

    postOrder(start, end); //좌
    postOrder(end+1, right); //우
    cout << tree[root] << '\n'; //루트
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int i=0, n;
    while(scanf("%d", &n) != EOF) tree[i++] = n;
    postOrder(0, i-1);
    
    return 0;
}

