import java.util.*;
import java.io.*;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        int[] ar = new int[n];
        for (int i = 0; i < n; i++) {
            ar[i] = Integer.parseInt(br.readLine());
        }

        int ans = 0, target = ar[n-1];
        for (int i = n - 2; i >= 0; i--) {
            target--;
            if (ar[i] <= target) {
                target = ar[i];
            } else {
                ans += ar[i] - target;
            }
        }
        System.out.println(ans);
    }
}
