import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.util.*;
import java.io.*;
import java.math.*;

public class solution {

    public double champagneTower(int poured, int query_row, int query_glass) {

        return 0.00;
    }

    public static void main(String[] args) throws FileNotFoundException {
        File f = new File("output.txt");

        // Scanner ip = new Scanner(System.in);
        try (Scanner ip = new Scanner(new File("input.txt")); PrintWriter op = new PrintWriter(f);) {

            // int x = 10;
            // int y = 11;
            // op.println(x + y);
            solution ob = new solution();
            double x = ob.champagneTower(2, 1, 1);
        }
    }
}