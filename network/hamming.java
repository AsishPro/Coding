import java.util.Scanner;

public class hamming {
    public static int findr(int m){
    int r=1;
        while(true){
            if(Math.pow(2,r)>=m+r+1){
                return r;
            }
            else
             r++;
        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        hamming.findr(m);
    }

}
