import java.util.*;

public class Solution {
    public static int solution(int[] A) {
        int answer = 0;
        int[] ar = new int[100010];
        for (int i = 0; i < A.length; i++) {
            ar[A[i]] = 1;
        }
        for (int i = 1; i <= 100001; i++) {
            if (ar[i] == 0) return i;
        }
        return answer;
    }

    public static void main(String[] args) {
        solution(new int[]{2, 3, 1, 5});
    }
}