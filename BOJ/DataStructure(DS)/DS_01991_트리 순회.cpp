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

//https://www.acmicpc.net/problem/1991 트리 순회

int n;
char ar[26][2];

void printOrder(char root, int flag) {
    char left = ar[root - 'A'][0];
    char right = ar[root - 'A'][1];
    
    if(flag == 0) cout << root;
    if(left != '.') printOrder(left, flag);
    if(flag == 1) cout << root;
    if(right != '.') printOrder(right, flag);
    if(flag == 2) cout << root;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++) {
        char node, left_child, right_child;
        cin >> node >> left_child >> right_child;
        ar[node - 'A'][0] = left_child;
        ar[node - 'A'][1] = right_child;
    }

    for(int i=0; i<3; i++) {
        printOrder('A', i);
        cout << '\n';
    }
    
    return 0;
}
