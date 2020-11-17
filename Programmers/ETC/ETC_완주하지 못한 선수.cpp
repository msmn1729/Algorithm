#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42576 완주하지 못한 선수

string solution(vector<string> part, vector<string> comp)
{
    unordered_map<string, int> d;
    for(auto i : part) d[i]++;
    for(auto i : comp) d[i]--;
    for(auto i : d) if(i.second) return i.first;
}