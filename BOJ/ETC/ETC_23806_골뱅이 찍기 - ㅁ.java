import java.io.*;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n * 5; j++) {
                System.out.print("@");
            }
            System.out.println();
        }

        for (int i = 0; i < n * 3; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print("@");
            }
            for (int j = 0; j < n * 3; j++) {
                System.out.print(" ");
            }
            for (int j = 0; j < n; j++) {
                System.out.print("@");
            }
            System.out.println();
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n * 5; j++) {
                System.out.print("@");
            }
            System.out.println();
        }
    }
}
