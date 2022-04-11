class Solution {
    public int solution(int[] numbers) {
        // 1번 풀이
//         int answer = 0;
//         int[] vis = new int[10];
        
//         for(int n : numbers) {
//             vis[n] = 1;
//         }
        
//         for(int i=0; i<10; i++) {
//             if(vis[i] == 0) answer += i;
//         }
//         return answer;
        
        // 2번 풀이
        int sum = 45;
        for(int n : numbers) sum -= n;
        return sum;
    }
}
