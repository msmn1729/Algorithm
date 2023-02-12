import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private final static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int switchCnt = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] ar = new int[switchCnt + 1];
        for (int i = 1; i <= switchCnt; i++) {
            ar[i] = Integer.parseInt(st.nextToken());
        }

        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int gender = Integer.parseInt(st.nextToken());
            int pos = Integer.parseInt(st.nextToken());

            if (gender == 1) {
                for (int j = pos; j <= switchCnt; j += pos) {
                    ar[j] ^= 1;
                }
            } else if (gender == 2) {
                ar[pos] ^= 1;
                for (int j = 1; ; j++) {
                    int left = pos - j;
                    int right = pos + j;
                    if (left < 1 || right > switchCnt) break;
                    if (ar[left] == ar[right]) {
                        ar[left] ^= 1;
                        ar[right] ^= 1;
                        continue;
                    }
                    break;
                }
            }
        }

        for (int i = 1; i <= switchCnt; i++) {
            System.out.print(ar[i] + " ");
            if (i % 20 == 0) {
                System.out.println();
            }
        }
    }
}
