import java.io.*;
import java.math.BigInteger;

public class Main {
    private final static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        BigInteger a = new BigInteger(br.readLine());
        char oper = br.readLine().charAt(0);
        BigInteger b = new BigInteger(br.readLine());

        if (oper == '+') {
            System.out.println(a.add(b));
        } else if (oper == '*') {
            System.out.println(a.multiply(b));
        }
    }
}
