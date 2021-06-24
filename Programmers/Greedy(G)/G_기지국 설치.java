import java.util.*;

class Solution {
    public int solution(int n, int[] stations, int w) {
        int answer = 0;
        int si = 0;
        int position = 1;
        while(position <= n) {
            // 새로 설치할 것이 범위 내에 겹치는 경우
            if(si < stations.length && stations[si] - w <= position) {
                position = stations[si++] + w + 1;
            }
            else {
                position += w * 2 + 1;
                answer++;
            }            
        }
        return answer;
    }
}