import java.util.*;

class producer extends Thread{
    int n;
    producer(){}
    producer(int n){
        this.n=n;
    }
    public void run(){
        for(int i=0;i<n;i++){
          System.out.println("Producer "+(i+1));
          try{
            Thread.sleep(100);
              Thread.currentThread().notify();
              
          }
          catch(Exception o){}
       } 
       
    }
}
class consumer extends Thread{
    int n;
    consumer(int n){
        this.n=n;
    }
    public void run(){
        
        for(int i=0;i<n;i++){
          try{
      
             Thread.sleep(100);
          }
          catch(Exception o){}
          System.out.println("Consumer "+(i+1));
        }
        System.out.println("Producer Terminating");
    }
}
public class synchro{
    static boolean a=false;
    public static void main(String[] args){
         producer o1=new producer(10);
         consumer o2=new consumer(10);  
         o1.start();
         o2.start();    
    }
    
}
