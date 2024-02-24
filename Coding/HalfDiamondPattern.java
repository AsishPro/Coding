import java.util.Scanner;

public class HalfDiamondPattern {
  public static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int n = input.nextInt();

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <=i; j++) {
        System.out.print(i);
        if(i!=j)
        System.out.print("*");
      }
      
      System.out.println();
    }

    for (int i = n; i >= 1; i--) {
      for (int j = 1; j <= i; j++) {
        System.out.print(i);
        if(i!=j)
        System.out.print("*");
      }
      System.out.println();
      
    }
  }
}