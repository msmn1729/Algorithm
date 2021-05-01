#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    bitset<20> bit(n);
    int cnt = bit.count();
    while(cnt != bitset<20>(++n).count());
    
    return n;
}
