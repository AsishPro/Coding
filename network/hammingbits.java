    import java.util.ArrayList;
    import java.util.Scanner;
    import java.lang.*;

    public class hammingbits {
        public static void main(String[] args){
            Scanner sc=new Scanner(System.in);
            int m=sc.nextInt();
            int r=hamming.findr(m);
            int sum=m+r;
            System.out.println("number of redundant bits: "+r);
            ArrayList<Integer> lt=new ArrayList<Integer>();
            for(int i=0;i<r;i++){
            int tem=(int)Math.pow(2,i);
            lt.add(tem);
            }
            System.out.println("Redundant bits: "+lt);
        }
    }
