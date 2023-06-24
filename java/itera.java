import java.util.ArrayList;
import java.util.List;
import java.util.ListIterator;

public class Itera {
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();
        list.add("apple");
        list.add("banana");
        list.add("cherry");

        // Create a list iterator for the list
        ListIterator<String> iterator = list.listIterator();

        // Iterate over the elements of the list in forward direction
        while (iterator.hasNext()) {
            String element = iterator.next();
            System.out.print(element + " ");
        }
        System.out.println();

        // Iterate over the elements of the list in backward direction
        while (iterator.hasPrevious()) {
            String element = iterator.previous();
            System.out.print(element + " ");
        }
        System.out.println();

        // Modify the elements of the list using the list iterator
        while (iterator.hasNext()) {
            String element = iterator.next();
            if (element.equals("banana")) {
                iterator.set("mango");
            }
        }

        // Print the modified elements of the list
        for (String element : list) {
            System.out.print(element + " ");
        }
        System.out.println();
    }
}