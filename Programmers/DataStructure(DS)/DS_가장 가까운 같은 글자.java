import java.util.*;

public class Solution {
    public static void main(String[] args) {
        solution("foobar");
    }

    public static int[] solution(String s) {
        int[] answer = new int[s.length()];
        Map<String, Integer> map = new HashMap<>();
        int idx = 0;

        for (int i = 0; i < s.length(); i++) {
            String token = String.valueOf(s.charAt(i));
            if (map.containsKey(token)) {
                answer[idx++] = i - map.get(token);
            } else {
                answer[idx++] = -1;
            }
            map.put(token, i);
        }
        return answer;
    }
}
