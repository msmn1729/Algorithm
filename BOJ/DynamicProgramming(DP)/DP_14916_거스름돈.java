import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        long dp[] = new long[100001];
        dp[1] = dp[3] = -1;
        dp[2] = dp[5] = 1;
        dp[4] = 2;
        dp[6] = 3;
        dp[7] = 2;
        dp[8] = 4;
        for (int i = 9; i <= n; i++) {
            dp[i] = Math.min(dp[i - 2], dp[i - 5]) + 1;
        }
        System.out.println(dp[n]);
    }
}