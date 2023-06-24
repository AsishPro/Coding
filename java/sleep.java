import java.util.*;
import java.lang.Exception;

class t extends Thread{
    public void run(){
        try{
            for(int i=0;i<8;i++){
                System.out.println("Welcome");
                Thread.sleep(1000);
            }
        }
        catch(Exception o1){
            System.out.print(o1);
        }
    }
}

class sleep {

public static void main (String[] args){
     t o1=new t();
      o1.start();
        try{
        System. out.println ("main ") ;
        Thread. sleep (1000) ;
        System.out.println ("main ") ;
        Thread.sleep (1000) ;
        System.out.println ("main ");
        Thread.sleep (1000) ;
        System.out.println ("main");
        Thread. sleep (1000) ;
        }
        catch (Exception a) {
            System.out .println ("main thread run is over" );
        }
}
}
