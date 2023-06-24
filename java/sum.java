import java.util.Scanner;

public class sum {
    public static void main(String[] args){
        Scanner o=new Scanner(System.in);
        System.out.print("Enter the Number between 0 and 1000 : ");
        int num=o.nextInt();
        int sum=0;
        while(num!=0){
          sum+=num%10;
          num=num/10;
        }
        System.out.println("the sum is: "+sum);
    }
}
