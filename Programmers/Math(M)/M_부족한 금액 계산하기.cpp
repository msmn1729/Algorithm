// https://programmers.co.kr/learn/courses/30/lessons/82612 부족한 금액 계산하기

#define ll long long
using namespace std;

ll solution(int price, int money, int count) {
    ll answer = (ll)price * (count * (count + 1) / 2) - money;
    if(answer <= 0) return 0;
    return answer;
}
