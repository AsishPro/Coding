import java.util.*;
class producer extends Thread{
    int n;
    String custom;
    producer(int n){
        this.n=n;
    }
    public void run(){
        for(int i=0;i<n;i++){
          System.out.println("Producer "+(i+1));
          try{
            Thread.currentThread().notify();
          }
          catch(Exception o){

          }
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
          System.out.println("Consumer "+(i+1));
          try{
            Thread.currentThread().wait();
          }
          catch(Exception o){

          }
        }
        
    }
}
public class not2{
    public static void main(String[] args){
         producer o1=new producer(3);
         consumer o2=new consumer(3);   
         o1.start();
         o2.start();    
    }
    
}
