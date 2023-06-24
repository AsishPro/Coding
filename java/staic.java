import java.util.*;
abstract  class k{
    abstract void run();
    void k(){
        System.out.println("good");
    }
}
public class staic extends k {
    void run(){
        System.out.print("ki");
    }
    void k(){
       super.run();
    }
    public static void main(String[] args){
        staic o1=new staic();
        o1.k();
        
        // int a[]=new int[20];
        // System.out.println(a.length);
        // String s="adadad";
        // System.out.print(s.length());
        // ArrayList<Integer> at=new ArrayList<Integer>();
        // System.out.print(at.size());
    }
}
