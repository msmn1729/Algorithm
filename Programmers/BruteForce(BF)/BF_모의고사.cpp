#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> v(3);

    int man1[5] = {1, 2, 3, 4, 5};
    int man2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int man3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    for(int i=0; i<answers.size(); i++) {
        int target = answers[i];
        cout << man3[i%10] << ' ';
        v[0] += (man1[i%5] == target);
        v[1] += (man2[i%8] == target);
        v[2] += (man3[i%10] == target);
    }

    int mx = *max_element(v.begin(), v.end());
    for(int i=0; i<v.size(); i++) {
        if(mx == v[i]) answer.push_back(i+1);
    }

    return answer;
}
