#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, const char * argv[]) {
    int zero_cnt, price, tmp = 5;
    cin >> price >> zero_cnt;
    if(zero_cnt == 0) cout << price;
    else
    {
        for(int i=0; i<zero_cnt-1; i++)
        {
            tmp *= 10;
        }
        cout << ((price + tmp) / (tmp*2) * (tmp*2));
    }
}
