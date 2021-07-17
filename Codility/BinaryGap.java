import java.util.*;

public class Solution {
    public static int solution(int n) {
        int oneCnt = 0;
        int maxCnt = 0;
        int flag = 0;

        while (n > 0) {
            System.out.print(n % 2);
            if (n % 2 == 1) {
                if (flag == 1) {
                    if (maxCnt < oneCnt) maxCnt = oneCnt;
                }
                flag = 1;
                oneCnt = 0;
            } else oneCnt++;
            n /= 2;
        }
        return maxCnt;
    }

    public static void main(String[] args) {
        solution(1041);
    }
}