package java.SlidingWindow_java;

// import static java.lang.Math.max;
// import static java.lang.Math.min;
// import static java.lang.Math.abs;
// import static java.lang.System.out;
import java.util.*;
import java.io.*;

public class Longest_Substring_Of_All_Vowels_in_Order_1839 {

    public int longestBeautifulSubstring(String s) {
        HashMap<Character, Boolean> mp = new HashMap<>();
        int ans = 0, i, j, t;
        mp.put(s.charAt(0), true);
        for (i = 1, j = 0; i < s.length(); ++i) {
            if (s.charAt(i) < s.charAt(i - 1)) {
                if (mp.size() == 5)
                    ans = Math.max(ans, i - j);
                j = i;
                mp.clear();
            }
            mp.put(s.charAt(i), true);
        }
        if (mp.size() == 5)
            ans = Math.max(ans, i - j);
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
            String s = "aeeeiiiioooauuuaeiou";

            // int grid[][] = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
            Longest_Substring_Of_All_Vowels_in_Order_1839 ob = new Longest_Substring_Of_All_Vowels_in_Order_1839();
            int ans = ob.longestBeautifulSubstring(s);
            op.println(ans);
        }
    }
}