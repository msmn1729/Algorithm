import java.util.*;

public class Solution {
    public static void main(String[] args) {
    }

    public static int dfs(Tree T) {
        if (T == null) {
            return 0;
        }
        return Math.max(dfs(T.l), dfs(T.r)) + 1;
    }

    public static int solution(Tree T) {
        return dfs(T) - 1;
    }
}
