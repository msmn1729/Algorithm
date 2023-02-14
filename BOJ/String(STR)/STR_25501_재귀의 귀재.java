import java.io.*;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static int cnt;

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        for (int i = 0; i < n; i++) {
            String word = br.readLine();
            cnt = 0;
            System.out.println(isPalindrome(word) + " " + cnt);
        }
    }

    public static int recursion(String word, int l, int r) {
        cnt++;
        if (l >= r) return 1;
        else if (word.charAt(l) != word.charAt(r)) return 0;
        return recursion(word, l + 1, r - 1);
    }

    public static int isPalindrome(String word) {
        return recursion(word, 0, word.length() - 1);
    }
}
