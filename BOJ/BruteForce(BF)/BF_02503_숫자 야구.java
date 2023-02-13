import java.io.*;
import java.util.*;

public class Main {
    private static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private static final List<BaseBallData> inputData = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int data = Integer.parseInt(st.nextToken());
            int strike = Integer.parseInt(st.nextToken());
            int ball = Integer.parseInt(st.nextToken());

            BaseBallData baseBallData = new BaseBallData(data, strike, ball);
            inputData.add(baseBallData);
        }

        int answer = calculatorBaseBall();
        System.out.println(answer);
    }

    private static int calculatorBaseBall() {
        int possibleCount = 0;

        for (int target = 123; target <= 987; target++) {
            if (isDuplicateNumCheck(target)) continue;

            boolean isPossible = true;
            for (BaseBallData baseBallData : inputData) {
                int data = baseBallData.data;
                int strike = baseBallData.strike;
                int ball = baseBallData.ball;

                String targetString = Integer.toString(target);
                String requstString = Integer.toString(data);

                int strikeCount = 0, ballCount = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (targetString.charAt(i) != requstString.charAt(j)) continue;
                        if (i == j) strikeCount++;
                        else ballCount++;
                    }
                }
                if (strike != strikeCount || ball != ballCount) {
                    isPossible = false;
                    break;
                }
            }
            if (isPossible) possibleCount++;
        }
        return possibleCount;
    }

    private static boolean isDuplicateNumCheck(int data) {
        String dataString = Integer.toString(data);
        int[] numCheck = new int[10];

        for (int i = 0; i < dataString.length(); i++) {
            int num = dataString.charAt(i) - '0';
            if (num == 0) return true;
            numCheck[num]++;
        }

        for (int i = 1; i <= 9; i++) {
            if (numCheck[i] >= 2) return true;
        }

        return false;
    }

    public static class BaseBallData {
        int data;
        int strike;
        int ball;

        public BaseBallData(int data, int strike, int ball) {
            this.data = data;
            this.strike = strike;
            this.ball = ball;
        }
    }
}
