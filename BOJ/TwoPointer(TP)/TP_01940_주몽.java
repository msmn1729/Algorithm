import java.util.*;
import java.io.*;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        String[] strings = br.readLine().split(" ");
        int[] ar = new int[n];
        for (int i = 0; i < n; i++) {
            ar[i] = Integer.parseInt(strings[i]);
        }
        Arrays.sort(ar);

        int st = 0, ed = n - 1;
        int ans = 0;
        while (st < ed) {
            int sum = ar[st] + ar[ed];
            if (sum < m) {
                st++;
            }
            else if (sum > m) {
                ed--;
            } else {
                st++;
                ed--;
                ans++;
            }
        }
        System.out.println(ans);
    }
}
