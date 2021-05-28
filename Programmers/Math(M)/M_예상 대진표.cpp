#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;
    a--;
    b--;
    while (a != b) {
        a = a >> 1;
        b = b >> 1;
        cout << a << ' ' << b << '\n';
        answer++;
    }
    return answer;
}
