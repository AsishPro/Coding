import java.util.Scanner;

public class subtotal {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the Subtotal: ");
        float sub=sc.nextFloat();
        System.out.print("Enter the Gratitude Rate: ");
        float rate=sc.nextFloat();
        float sum=sub+(sub*rate)/100;
        System.out.println("The Total is: "+sum);
    }
}
