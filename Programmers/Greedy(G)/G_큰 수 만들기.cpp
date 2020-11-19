#include <string>
#include <vector>

using namespace std;

//https://programmers.co.kr/learn/courses/30/lessons/42883 큰 수 만들기

string solution(string number, int k) 
{
    string answer = "";
    for(int i=0; i<number.size(); i++)
    {
        while(k && answer.size() && answer.back() < number[i])
        {
            answer.pop_back();
            k--;
        }
        answer += number[i];
    }
    while(k--) answer.pop_back();
    
    return answer;
}