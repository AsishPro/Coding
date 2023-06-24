import java.util.Scanner;
public class test{
    void method(int n,char c){
      System.out.println(n+" "+c);
    }
    void method(char c,int n){
      System.out.println(c+" "+n);
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
       int n=sc.nextInt();
       char c=sc.next().charAt(0);
       test o1=new test();
       o1.method(n,c);
       o1.method(c,n);
    }
}
