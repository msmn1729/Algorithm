import java.util.*;
import java.io.*;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int c = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());

        int numerator = a * d + b * c;
        int denominator = b * d;

        int mod = gcd(numerator, denominator);
        numerator /= mod;
        denominator /= mod;
        System.out.println(numerator + " " + denominator);
    }

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        if (a <= b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        return gcd(b, a % b);
    }
}
