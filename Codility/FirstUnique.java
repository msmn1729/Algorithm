import java.util.*;

public class Solution {
    public static void main(String[] args) {
        System.out.println(solution(new int[]{1, 4, 3, 3, 1, 2}));
    }

    public static int solution(int[] A) {
        HashMap<Integer, Integer> numCheckMap = new HashMap<>();
        for (int num : A) {
            if (numCheckMap.containsKey(num)) {
                numCheckMap.put(num, numCheckMap.get(num) + 1);
            } else {
                numCheckMap.put(num, 1);
            }
        }

        for (int num : A) {
            if(numCheckMap.get(num) == 1) return num;
        }

        return -1;
    }
}
