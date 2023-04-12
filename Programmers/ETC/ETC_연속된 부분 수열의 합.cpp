#include <iostream>
#include <vector>
#define ll long long
#define INF 1e9
using namespace std;

const int MOD = INF + 7;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer = {0, (int)sequence.size() - 1}; // 초기값: 전체 수열

    int left = 0, right = 0, sum = sequence[0];

    while (right < sequence.size()) {
        if (sum == k) { // 합이 k인 부분 수열을 찾은 경우
            if (right - left < answer[1] - answer[0]) { // 기존에 찾은 부분 수열보다 길이가 짧은 경우
                answer[0] = left;
                answer[1] = right;
            }
            sum -= sequence[left++]; // left를 오른쪽으로 이동시키면서 합에서 left에 해당하는 값을 뺀다.
        }
        else if (sum < k) { // 현재 합이 k보다 작은 경우, right를 오른쪽으로 이동시킨다.
            if (++right < sequence.size())
                sum += sequence[right];
        }
        else { // 현재 합이 k보다 큰 경우, left를 오른쪽으로 이동시킨다.
            sum -= sequence[left++];
        }
    }

    return answer;
}
