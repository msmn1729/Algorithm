#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l_prev = 10, r_prev = 12;
    
    for(int n: numbers) {
        if(n==0) n = 11;
        if(n==1 || n==4 || n==7) {
            answer += "L";
            l_prev = n;
        }
        else if(n==3 || n==6 || n==9) {
            answer += "R";
            r_prev = n;
        }
        else {
            int lx = (l_prev-1)/3, ly = (l_prev-1)%3;
            int rx = (r_prev-1)/3, ry = (r_prev-1)%3;
            int nx = (n-1)/3, ny = (n-1)%3;
            int dif_lx = abs(lx-nx) + abs(ly-ny);
            int dif_rx = abs(rx-nx) + abs(ry-ny);

            if(dif_lx < dif_rx) {
                answer += "L";
                l_prev = n;
            }
            else if(dif_lx > dif_rx) {
                answer += "R";
                r_prev = n;
            }
            else {
                char c = hand[0] - ('a' - 'A');
                answer += c;
                if(c == 'L') l_prev = n;
                else r_prev = n;
            }
        }
    }
    
    return answer;
}
