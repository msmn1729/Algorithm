import java.util.*;
import java.io.*;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            StringTokenizer st = new StringTokenizer(s);

            while (st.hasMoreTokens()) {
                String rWord = new StringBuilder(st.nextToken()).reverse().toString();
                System.out.print(rWord + " ");
            }
            System.out.println();
        }
    }
}
