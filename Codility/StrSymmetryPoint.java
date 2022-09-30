import java.util.*;

public class Solution {
    public static void main(String[] args) {
        System.out.println(solution("a"));
    }

    public static int solution(String S) {
        if (S.length() % 2 == 0) {
            return -1;
        }
        for (int i = 0; i < S.length() / 2; i++) {
            if (S.charAt(i) != S.charAt(S.length() - i - 1)) {
                return -1;
            }
        }
        return S.length() / 2;
    }
}
