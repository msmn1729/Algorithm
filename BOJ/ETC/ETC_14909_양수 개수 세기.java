import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int answer = 0;

        while (st.hasMoreTokens()) {
            int num = Integer.parseInt(st.nextToken());
            if (num > 0) {
                answer++;
            }
        }

        System.out.println(answer);
    }
}
