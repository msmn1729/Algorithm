import java.io.*;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int answer = 4, prev = 2;

        for (int i = 1; i <= n; i++) {
            int cur = 2 * prev - 1;
            answer += Math.pow(cur, 2) - Math.pow(prev, 2);
            prev = cur;
        }
        System.out.println(answer);
    }
}
