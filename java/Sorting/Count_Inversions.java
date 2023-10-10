package java.Sorting;

import java.util.*;
import java.io.*;

// import static java.lang.Math.max;
// import static java.lang.Math.min;
// import static java.lang.Math.abs;
// import static java.lang.System.out;

class Count_Inversions {
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    static long ans = 0;

    public static void merge(long nums[], int start, int mid, int end) {
        // merge two sorted array concept work
        int f = start;
        int s = mid;
        ArrayList<Long> temp = new ArrayList<Long>();

        while (f < mid && s <= end) {
            if (nums[f] <= nums[s]) {
                temp.add(nums[f++]);
            } else {
                ans += (mid - f);
                temp.add(nums[s++]);
            }
        }
        while (f < mid) {
            temp.add(nums[f++]);
        }
        while (s <= end) {
            temp.add(nums[s++]);
        }
        f = 0;
        while (start <= end) {
            nums[start] = temp.get(f);
            ++start;
            ++f;
        }
    }

    public static void mergeSort(long nums[], int s, int e) {
        if (s == e)
            return;
        int mid = (s + e) / 2;
        if (s < e) {
            mergeSort(nums, s, mid);
            mergeSort(nums, mid + 1, e);
            merge(nums, s, mid + 1, e);
        }
    }

    static long inversionCount(long arr[], long N) {
        // Your Code Here
        ans = 0; // because ans i static so keep intialize ans=0 in case of multiple testcase
        Count_Inversions.mergeSort(arr, 0, (int) (N - 1));
        return ans;
    }

    public static void main(String[] args) throws FileNotFoundException {
        File f = new File("output.txt");

        // Scanner ip = new Scanner(System.in);
        try (Scanner ip = new Scanner(new File("input.txt"));
                PrintWriter op = new PrintWriter(f);) {

            long nums[] = { 2, 4, 1, 3, 5 };
            op.println(new Count_Inversions().inversionCount(nums, 5));

        }
    }

}