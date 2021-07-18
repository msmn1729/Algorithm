import java.util.*;

public class Solution {
    public static int solution(int X, int Y, int D) {
        int answer = 0;
        if(X == Y) return 0;
        answer = (Y - X - 1) / D + 1;
        return answer;
    }

    public static void main(String[] args) {
        solution(10, 85, 30);
    }
}