import java.util.*;

public class hash {

    private int[] arr;
    private int sum;

    public void readArray() {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
         sum = scanner.nextInt();
    }

    public void findPairs() {
        Set<Integer> set = new HashSet<>();
        for (int num : arr) {
            set.add(num);
        }
        boolean foundPair = false;
        for (int num : arr) {
            int complement = sum - num;
            if (set.contains(complement)) {
                System.out.println(num + " " + complement);
                foundPair = true;
            }
            set.add(num);
        }
        if (!foundPair) {
            System.out.println("No pairs found with sum equal to " + sum);
        }
    }

    public static void main(String[] args) {
        hash pairSumFinder = new hash();
        pairSumFinder.readArray();
        pairSumFinder.findPairs();
    }
}