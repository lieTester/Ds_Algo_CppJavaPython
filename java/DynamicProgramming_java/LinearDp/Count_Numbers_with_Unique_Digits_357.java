package java.DynamicProgramming_java.LinearDp;

import java.util.*;
import java.io.*;

// import static java.lang.Math.max;
// import static java.lang.Math.min;
// import static java.lang.Math.abs;
// import static java.lang.System.out;

public class Count_Numbers_with_Unique_Digits_357 {
    public int countNumbersWithUniqueDigits(int n) {
        /*
         * pattern 0=1
         * 1=9
         * 2=9*[1]
         * 3=8*[2]
         * 4=7*[3]
         * 5=6*[4]
         * -------------
         * add all them
         * 
         * 
         */

        if (n < 2)
            return n == 0 ? 1 : 10;
        int dp[] = new int[n + 1];
        dp[0] = 1;
        dp[1] = 9;
        int ans = 10;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] * dp[1]--;
            ans += dp[i];
        }
        return ans;
    }

    public static void main(String[] args) throws FileNotFoundException {
        File f = new File("output.txt");

        // Scanner ip = new Scanner(System.in);
        try (Scanner ip = new Scanner(new File("input.txt"));
                PrintWriter op = new PrintWriter(f);) {
            Count_Numbers_with_Unique_Digits_357 obj = new Count_Numbers_with_Unique_Digits_357();
            // int nums[] = { 1, 3, 5, 10 };

            op.println(obj.countNumbersWithUniqueDigits(6));

        }
    }

}