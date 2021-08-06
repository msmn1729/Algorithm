import java.util.*;
import java.io.*;
// https://www.acmicpc.net/problem/1935 후위 표기식2

public class Main {
    private static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int n = Integer.parseInt(br.readLine());
        Map<Character, Integer> map = new HashMap<>();
        String input = br.readLine();

        for (int i = 0; i < n; i++) {
            map.put((char) ('A' + i), Integer.parseInt(br.readLine()));
        }

        Stack<Double> stack = new Stack<>();
        for (char c : input.toCharArray()) {
            if (Character.isAlphabetic(c)) {
                stack.push(Double.valueOf(map.get(c)));
            } else {
                double b = stack.pop();
                double a = stack.pop();
                if (c == '+') {
                    stack.push(a + b);
                } else if (c == '-') {
                    stack.push(a - b);
                } else if (c == '*') {
                    stack.push(a * b);
                } else if (c == '/') {
                    stack.push(a / b);
                }
            }
        }
        System.out.format("%.2f", stack.pop());
    }
}