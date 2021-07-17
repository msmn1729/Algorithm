import java.util.*;

public class Solution {
    public static int[] solution(int[] A, int K) {
        int ar[] = new int[A.length];
        for (int i = 0; i < A.length; i++) {
            ar[(i + K) % A.length] = A[i];
        }
        return ar;
    }

    public static void main(String[] args) {
        solution(new int[]{3, 8, 9, 7, 6}, 3);
    }
}