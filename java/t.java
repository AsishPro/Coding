import java.util.*;


public class t {
  public static void main(String args[]) {
    int str;
    Scanner sc = new Scanner(System.in);
    System.out.print("Enter any integer number: ");
    str = sc.nextInt();

    // String str = Integer.toBinaryString(num);
    // System.out.println("Binary number is : " + str);
    // int num=Integer.parseInt(str,2);
    // System.out.println(num);
    String s=Integer.toString(str,16); 
    System.out.println(s);

  }
}