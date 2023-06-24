import java.util.*;

class game {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int balls = sc.nextInt();
        int slots = sc.nextInt();
        int[] array = new int[slots];
        for (int i = 1; i <= balls; i++) { 
            array = Path(slots,i,array);
        }
        System.out.println("Where 1 is equal to a ball in the slot, the slots after all balls are dropped is: ");
        System.out.print(Arrays.toString(array));
    }
    public static int[] Path(int slots,int ballno,int array[]) {
        char[] result = new char[slots];
        for (int i = 0; i < slots; i++) {
            int random = (int)(Math.random() * 2);
            result[i] = (random == 0) ? 'R' : 'L';
        }
        int slot = 0;
        System.out.println("Ball number " + ballno + " falls down path: " + Arrays.toString(result));
        for (char c : result) {
            if (c == 'R') {
                slot++;
            }
        }
        System.out.println("And lands in slot number: " + slot);
        array[slot - 1] ++;
        return array;
    }
}