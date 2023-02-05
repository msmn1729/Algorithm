import java.io.*;

public class Main {
    private final static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        String s = br.readLine();
        String[] nums = s.split(",");
        int sum = 0;

        for (int i = 0; i < nums.length; i++) {
            sum += Integer.parseInt(nums[i]);
        }

        System.out.println(sum);
    }
}
