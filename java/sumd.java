import java.util.Scanner;

class sumd{
    public static void main(String args[]){
        int t;
        Scanner sc=new Scanner(System.in);
        t=sc.nextInt();
        System.out.println((t%9==0)?9:0);
    }
}