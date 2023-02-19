import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String input = br.readLine();
        int radix = 10;

        if (input.startsWith("0x")) {
            input = input.substring(2);
            radix = 16;
        } else if (input.startsWith("0")) {
            input = input.substring(1);
            radix = 8;
        }

        String answer = new BigInteger(input, radix).toString();
        System.out.println(answer);
    }
}
