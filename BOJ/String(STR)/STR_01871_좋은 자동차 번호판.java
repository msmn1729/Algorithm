import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            String[] nums = br.readLine().split("-");
            String alpa = nums[0];
            int num1 = (alpa.charAt(0) - 'A') * (26 * 26) + (alpa.charAt(1) - 'A') * 26
                    + (alpa.charAt(2) - 'A');
            int num2 = Integer.parseInt(nums[1]);

            if (Math.abs(num1 - num2) > 100) {
                System.out.print("not ");
            }
            System.out.println("nice");
        }
    }
}
