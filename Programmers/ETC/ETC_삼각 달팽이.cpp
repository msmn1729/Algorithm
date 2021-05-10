#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    int ar[1000][1000] = {};
    vector<int> answer;
    
    int x = -1, y = 0;
    int cnt = 1;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n-i; j++) {
            if(i%3 == 0) x++;
            else if(i%3 == 1) y++;
            else {
                x--;
                y--;
            }
            ar[x][y] = cnt++;
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            answer.push_back(ar[i][j]);
        }
    }
    
    return answer;
}
