import java.util.*;

public class Solution {
    public static int solution(int[] A) {
        int answer = 0;
        Map<Integer, Integer> countMap = new HashMap<>();

        for (int i = 0; i < A.length; i++) {
            Integer target = countMap.get(A[i]);
            if (target == null) {
                countMap.put(A[i], 1);
            } else {
                countMap.remove(A[i]);
            }
        }
        for (Integer key : countMap.keySet()) {
            return key;
        }
        return answer;
    }

    public static void main(String[] args) {
        solution(new int[]{9, 3, 9, 3, 9, 7, 9});
    }
}