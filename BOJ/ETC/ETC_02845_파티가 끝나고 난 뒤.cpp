#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int l, p;
    cin >> l >> p;
    int totalPeople = l * p;
    
    for(int i=0; i<5; i++) {
        int n;
        cin >> n;
        cout << n - totalPeople << ' ';
    }
    return 0;
}
