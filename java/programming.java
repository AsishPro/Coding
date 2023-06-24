import java.util.*;
public class programming {
    programming(){
        System.out.println("I love programming languages");
    }
    programming(String s){
        System.out.println("I love "+s);
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String c=sc.nextLine();
        programming o1=new programming();
        programming o2=new programming(c);
    }
}