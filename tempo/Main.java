import java.util.Scanner;

class Box {
    double width, height, depth;

    Box(double w, double h, double d) {
        width = w;
        height = h;
        depth = d;
    }

    public double getVolume() {
        return width * height * depth;
    }
}

class Main {
    public static void main(String[] args) {
        // take input from the user
        Scanner scanner = new Scanner(System.in);
        double width = scanner.nextDouble();
        double height = scanner.nextDouble();
        double depth = scanner.nextDouble();

        // create an object of Box class
        Box box = new Box(width, height, depth);

        // check if the input is valid
        if (width <= 0 || height <= 0 || depth <= 0) {
            System.out.println("Invalid input.");
        } else {
            // calculate and display the volume of the box
            System.out.printf("Volume of the box: " + "%.2f",(box.getVolume()));
        }
    }
}