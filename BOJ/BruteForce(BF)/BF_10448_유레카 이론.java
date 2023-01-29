import java.io.*;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int[] ar = new int[51];

    private static int isEurekaNum(int n) {
        for (int j = 1; j <= 50; j++) {
            for (int k = 1; k <= 50; k++) {
                for (int l = 1; l <= 50; l++) {
                    if (ar[j] + ar[k] + ar[l] != n) {
                        continue;
                    }
                    return 1;
                }
            }
        }
        return 0;
    }

    public static void main(String[] args) throws IOException {
        int t = Integer.parseInt(br.readLine());

        for (int i = 1; i <= 50; i++) {
            ar[i] = i * (i + 1) / 2;
        }

        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            System.out.println(isEurekaNum(n));
        }
    }
}
