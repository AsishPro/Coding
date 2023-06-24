import java.util.Scanner;

public class special {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        while(m<=n){
            int x=m;
            int sum=0;
            while(x!=0){
                sum+=x%10;
                x=x/10;
            }
            x=m;
            int pro=1;
            while(x!=0){
               pro*=x%10;
               x=x/10;
            }
            if(sum+pro==m){
            System.out.println(m);
            }
            m++;
        }
    }
}
