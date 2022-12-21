import java.util.*;
import java.io.*;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int dasom = Integer.parseInt(br.readLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < n-1; i++) {
            int in = Integer.parseInt(br.readLine());
            pq.add(in);
        }
        
        int ans = 0;
        while (!pq.isEmpty() && dasom <= pq.peek()) {
            dasom++;
            ans++;
            pq.add(pq.poll() - 1);
        }

        System.out.println(ans);
    }
}
