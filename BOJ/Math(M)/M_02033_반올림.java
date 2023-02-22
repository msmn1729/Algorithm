import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String strN = br.readLine();
        int n = Integer.parseInt(strN);

        for (int i = 1, cnt = 1; cnt < strN.length(); i *= 10, cnt++) {
            n += 5 * i;
            n = (n / (i * 10)) * (i * 10); 
        }
        System.out.println(n);
    }
}
