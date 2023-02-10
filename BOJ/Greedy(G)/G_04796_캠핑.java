import java.io.*;
import java.util.*;

public class Main {
    private final static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        for (int i = 1; ; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int L = Integer.parseInt(st.nextToken());
            int P = Integer.parseInt(st.nextToken());
            int V = Integer.parseInt(st.nextToken());

            if (L == 0 && P == 0 && V == 0) {
                break;
            }
            int answer = L * (V / P) + Math.min(V % P, L);
            System.out.println("Case " + i + ": " + answer);
        }
    }
}
