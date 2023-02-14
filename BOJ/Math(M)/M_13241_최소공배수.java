import java.io.*;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong((st.nextToken()));
        long answer = a * b / GCD(a, b);
        System.out.println(answer);
    }

    public static long GCD(long a, long b) {
        if (a % b == 0) return b;
        return GCD(b, a % b);
    }
}
