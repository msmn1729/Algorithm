import java.io.*;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String word = br.readLine();
        List<String> words = new ArrayList<>();

        for (int i = 0; i < word.length(); i++) {
            for (int j = i + 1; j < word.length(); j++) {
                String s1 = word.substring(0, i);
                String s2 = word.substring(i, j);
                String s3 = word.substring(j);
                if (s1.isEmpty()) continue;
                s1 = reverseWord(s1);
                s2 = reverseWord(s2);
                s3 = reverseWord(s3);
                words.add(s1 + s2 + s3);
            }
        }
        Collections.sort(words);
        System.out.println(words.stream().findFirst().get());
    }

    private static String reverseWord(String word) {
        StringBuilder sb = new StringBuilder(word);
        return sb.reverse().toString();
    }
}
