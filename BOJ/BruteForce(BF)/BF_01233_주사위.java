import java.util.*;
import java.io.*;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int s1 = Integer.parseInt(st.nextToken());
        int s2 = Integer.parseInt(st.nextToken());
        int s3 = Integer.parseInt(st.nextToken());

        int[] numCnt = new int[s1 + s2 + s3 + 1];
        for (int i = 1; i <= s1; i++) {
            for (int j = 1; j <= s2; j++) {
                for (int k = 1; k <= s3; k++) {
                    int sum = i + j + k;
                    numCnt[sum]++;
                }
            }
        }

        int ans = 0, mx = 0;
        for (int i = 1; i <= s1 + s2 + s3; i++) {
            if (mx >= numCnt[i]) {
                continue;
            }
            mx = numCnt[i];
            ans = i;
        }
        System.out.println(ans);
    }
}
