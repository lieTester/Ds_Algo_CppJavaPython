package java.Greedy_java;

// import static java.lang.Math.max;
// import static java.lang.Math.min;
// import static java.lang.Math.abs;
// import static java.lang.System.out;
import java.util.*;
import java.io.*;

// import java.math.*;
public class Max_Increase_to_Keep_City_Skyline_807 {

    // logic is we store sum of all vowels come after curr vowels
    // initital we have [1,1,1,1,1] n==1
    // n==2 ,both index including
    // dp[0 or a]= previous dp[0-4]
    // dp[1 or e]= previous dp[1-4]
    // dp[2 or i]= previous dp[2-4]
    // dp[3 or o]= previous dp[3-4]
    // dp[4 or u]= previous dp[4-4]

    public int maxIncreaseKeepingSkyline(int[][] g) {
        int m = g.length, n = g[0].length;
        int[] row = new int[m];
        int[] col = new int[n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                col[j] = Math.max(col[j], g[i][j]);
                row[i] = Math.max(row[i], g[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // how much we are increasing
                ans += Math.min(col[j], row[i]) - g[i][j];
                g[i][j] = Math.min(col[j], row[i]);
            }
        }
        return ans;
    }

    public static void main(String[] args) throws FileNotFoundException {
        File f = new File("output.txt");

        // Scanner ip = new Scanner(System.in);
        try (Scanner ip = new Scanner(new File("input.txt"));
                PrintWriter op = new PrintWriter(f);) {

            // int x = ip.nextInt();
            // int y = ip.nextInt();
            // op.println(x + y);
            int grid[][] = { { 3, 0, 8, 4 }, { 2, 4, 5, 7 }, { 9, 2, 6, 3 }, { 0, 3, 1, 0 } };
            Max_Increase_to_Keep_City_Skyline_807 ob = new Max_Increase_to_Keep_City_Skyline_807();
            int ans = ob.maxIncreaseKeepingSkyline(grid);
            op.println(ans);
        }
    }
}