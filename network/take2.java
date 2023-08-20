import java.util.ArrayList;
import java.util.Scanner;

public class take2 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        ArrayList<Integer> lt=new ArrayList<Integer>();
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
            lt.add(sc.nextInt());
        }
        int c=0;
        for(int i:lt){
            if(i==1)
                c++;
        }
        System.out.print("parity : "+c%2);

    }
}
