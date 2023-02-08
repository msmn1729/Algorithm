import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    private final static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int answer = 0;
        int cnt = 0;

        for (int i = 0; i < 10; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int down = Integer.parseInt(st.nextToken());
            int up = Integer.parseInt(st.nextToken());

            cnt = cnt - down + up;
            answer = Math.max(answer, cnt);
        }
        System.out.println(answer);
    }
}
