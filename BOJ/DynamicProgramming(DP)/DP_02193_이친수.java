import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        long dp[][] = new long[100][2];
        dp[1][1] = 1L;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 2; i <= n; i++) {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
        }
        System.out.println(dp[n][0] + dp[n][1]);
    }
}