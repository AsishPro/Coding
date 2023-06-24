import java.util.Arrays;
import java.util.Scanner;

public class newballs{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Enter the number of balls to drop: ");
        int numBalls = input.nextInt();

        System.out.print("Enter the number of slots in the bean machine: ");
        int numSlots = input.nextInt();

        int[] slots = new int[numSlots]; // initialize all slots to 0

        System.out.println();

        for (int i = 1; i <= numBalls; i++) {
            String path = getPath(numSlots);
            int slot = getSlot(path);
            slots[slot]++;
            System.out.println("Ball number " + i + " falls down path: " + path);
            System.out.println("And lands in slot number: " + slot);
            System.out.println();
        }

        System.out.println("Final buildup of the balls in the slots:");
        System.out.println(Arrays.toString(slots));
        for (int i = numBalls; i > 0; i--) {
            for (int j = 0; j < numSlots; j++) {
                if (slots[j] >= i) {
                    System.out.print("O ");
                } else {
                    System.out.print("  ");
                }
            }
            System.out.println();
        }
    }

    public static String getPath(int numSlots) {
        StringBuilder path = new StringBuilder();
        for (int i = 0; i < numSlots - 1; i++) {
            path.append((Math.random() < 0.5) ? "L" : "R");
        }
        return path.toString();
    }

    public static int getSlot(String path) {
        int slot = 0;
        for (int i = 0; i < path.length(); i++) {
            if (path.charAt(i) == 'R') {
                slot++;
            }
        }
        return slot;
    }
}