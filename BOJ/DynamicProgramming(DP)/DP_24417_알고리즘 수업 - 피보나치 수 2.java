import java.util.*;
import java.io.*;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int a = 1, b = 1, sum = 0;

        for (int i = 3; i <= n; i++) {
            sum = a + b;
            sum %= 1e9 + 7;
            a = b;
            b = sum;
        }
        System.out.println(sum + " " + (n - 2));
    }
}
