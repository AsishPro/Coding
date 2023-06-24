import java.util.Scanner;

class sum2_d{
    public static void main(String args[]){
        int t;
        Scanner sc=new Scanner(System.in);
        t=sc.nextInt();
        int sum=0;
      while(t>=10){
        while(t!=0){
            sum+=t%10;
            t=t/10;
        }
        t=sum;
        sum=0;
       }  
        System.out.println(sum);
    }
}