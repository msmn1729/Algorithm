#include <iostream>

using namespace std;

//https://www.acmicpc.net/problem/14681 사분면 고르기

int main(int argc, const char * argv[]) {
    int x, y;
    cin >> x >> y;
    if(x > 0 && y > 0) cout << "1";
    else if(x < 0 && y > 0) cout << "2";
    else if(x < 0 && y < 0) cout << "3";
    else cout << "4";
    return 0;
}
