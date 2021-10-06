#include <iostream>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int n, kim, im;
    cin >> n >> kim >> im;
    
    for(int i=1; i<=100; i++) {
        kim = (kim + 1) / 2;
        im = (im + 1) / 2;
        
        if(kim == im) {
            cout << i;
            return 0;
        }
    }
    
    return 0;
}
