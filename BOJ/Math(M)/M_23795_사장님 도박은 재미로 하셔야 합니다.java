import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int sum = 0;

        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == -1) break;
            sum += n;
        }
        System.out.println(sum);
    }
}
