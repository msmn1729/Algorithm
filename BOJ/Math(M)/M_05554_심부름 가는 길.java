import java.io.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int minute = 0, second = 0;

        for (int i = 0; i < 4; i++) {
            int num = Integer.parseInt(br.readLine());
            second += num;
        }

        minute = second / 60;
        second %= 60;

        System.out.println(minute);
        System.out.println(second);
    }
}
