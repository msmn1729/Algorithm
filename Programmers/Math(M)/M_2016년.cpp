#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    int sum = b + 4;
    int ar[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for(int i=1; i<=a-1; i++) sum += ar[i];
    sum %= 7;
    answer = day[sum];
    
    return answer;
}