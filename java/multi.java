import java.util.*;
import java.lang.Exception;

class t extends Thread{
    public void run(){
        try{
            for(int i=0;i<8;i++){
                System.out.print("Welcome");
                Thread.sleep(5000);
            }
        }
        catch(Exception o1){
            System.out.print(o1);
        }
    }
}
public class multi {
    public static void main(String[] args){
      t o1=new t();
      o1.setPriority(10);
      o1.start();
      for(int i=0;i<50;i++){
        System.out.print(i+" ");
      }
    }
}
