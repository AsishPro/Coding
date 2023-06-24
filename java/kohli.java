import java.util.*;
public class kohli {
    String str="Unknown";
    kohli(){
        System.out.print(str);
    }
    kohli(String s){
        str=s;
        System.out.println(str);
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        kohli o1=new kohli(sc.nextLine());
        kohli o2=new kohli();
    }
}
