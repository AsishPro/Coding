import java.util.*;
public class grade {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        if(n<0)
        System.out.println("Invald");
        else if(n>=85)
        System.out.println("A");
        else if(n>=75 && n<85)
        System.out.println("B");
        else if(n>=65 && n<75)
        System.out.println("C");
        else 
        System.out.println("D");
    }
}
