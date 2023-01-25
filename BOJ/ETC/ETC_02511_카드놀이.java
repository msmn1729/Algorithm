import java.util.*;
import java.io.*;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String[] arA = br.readLine().split(" ");
        String[] arB = br.readLine().split(" ");

        int scoreA = 0, scoreB = 0;
        int lastWin = 0;
        for (int i = 0; i < arA.length; i++) {
            int a = Integer.parseInt(arA[i]);
            int b = Integer.parseInt(arB[i]);

            if (a > b) {
                scoreA += 3;
                lastWin = 1;
            } else if (a < b) {
                scoreB += 3;
                lastWin = 2;
            } else {
                scoreA++;
                scoreB++;
            }
        }

        System.out.println(scoreA + " " + scoreB);
        if (scoreA > scoreB) {
            System.out.println("A");
        } else if (scoreA < scoreB) {
            System.out.println("B");
        } else if (lastWin == 1) {
            System.out.println("A");
        } else if (lastWin == 2) {
            System.out.println("B");
        } else {
            System.out.println("D");
        }
    }
}
