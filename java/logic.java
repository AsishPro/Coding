import java.util.Scanner;

public class logic {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int sum=6;
        int i=0,k=5;
        while(i<n){
           sum+=(k*i);
           System.out.print(sum+" ");
           i++;
        }
    }
}
