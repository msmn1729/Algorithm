import java.io.*;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String color1 = br.readLine();
        String color2 = br.readLine();
        String color3 = br.readLine();

        HashMap<String, String> m = new HashMap<>() {{
            put("black", "0");
            put("brown", "1");
            put("red", "2");
            put("orange", "3");
            put("yellow", "4");
            put("green", "5");
            put("blue", "6");
            put("violet", "7");
            put("grey", "8");
            put("white", "9");
        }};

        long ans = Long.parseLong(m.get(color1) + m.get(color2));
        ans *= Math.pow(10, Long.parseLong(m.get(color3)));
        System.out.println(ans);
    }
}
