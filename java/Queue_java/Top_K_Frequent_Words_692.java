package java.Queue_java;

import java.util.*;
import java.io.*;

// import static java.lang.Math.max;
// import static java.lang.Math.min;
// import static java.lang.Math.abs;
// import static java.lang.System.out;
class Pair {
    public String name;
    public Integer count;

    // A parameterized Pair constructor
    public Pair(Integer count, String name) {

        this.name = name;
        this.count = count;
    }
}

class FreqComparator implements Comparator<Pair> {
    public int compare(Pair p1, Pair p2) {
        if (p1.count == p2.count)
            return p1.name.compareTo(p2.name);
        return p2.count - p1.count;
    }
}

public class Top_K_Frequent_Words_692 {

    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>(k, new FreqComparator());
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            String key = entry.getKey();
            int val = entry.getValue();
            pq.add(new Pair(val, key));
        }
        List<String> result = new ArrayList<>();
        while (!pq.isEmpty() && k > 0) {
            Pair top = pq.poll();
            k--;
            result.add(top.name);
        }
        return result;
    }

    public static void main(String[] args) throws FileNotFoundException {
        File f = new File("output.txt");

        // Scanner ip = new Scanner(System.in);
        try (Scanner ip = new Scanner(new File("input.txt"));
                PrintWriter op = new PrintWriter(f);) {
            Top_K_Frequent_Words_692 obj = new Top_K_Frequent_Words_692();
            String grid[] = { "i", "love", "leetcode", "i", "love", "coding" };
            op.println(obj.topKFrequent(grid, 2));

        }
    }

}
