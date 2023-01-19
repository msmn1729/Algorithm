#include <iostream>
#include <string>
using namespace std;
int main() {
    string k;
    int cnt = 0;
    cin >> k;
    for (int i = 0; i < k.size(); i++)
    {
        if (k[i] == ',')
            cnt++;
    }
    cout << cnt + 1 << '\n';
}
