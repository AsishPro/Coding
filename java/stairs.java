import java.util.*;
public class stairs {
    public static void main(String[]  args){
         Scanner sc=new Scanner(System.in);
         int n=sc.nextInt();
         int v1=sc.nextInt();
         int v2=sc.nextInt();
         double d1=Math.sqrt(2)*n;
         double d2=2*n;
         double t1=d1/v1;
         double t2=d2/v2;
         if(t1<t2)
         System.out.print("Stairs");
         else
         System.out.print("Elevator");
    }
}
