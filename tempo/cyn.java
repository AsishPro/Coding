import java.util.*;

class producer extends Thread{
    int n;
    producer(){}
    producer(int n){
        this.n=n;
    }
    public void run(){
        for(int i=0;i<n-1;i++){
          System.out.println("Producer ::: "+(i+1));
          try{
              Thread.sleep(100);
              Thread.currentThread().notify();  
          }
          catch(Exception o){}
       } 
       System.out.println("Producer Terminating.");
       System.out.println("Consumer ::: "+(n));
    }
}
class consumer extends Thread{
    int n;
    consumer(int n){
        this.n=n;
    }
    public void run(){
        
        for(int i=0;i<n-1;i++){
          try{
            Thread.sleep(101);
            Thread.currentThread().wait();    
          }
          catch(Exception o){}
          System.out.println("Consumer ::: "+(i+1));
        }
        System.out.println("Producer ::: "+(n));
    }
}
public class cyn{
    static boolean a=false;
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
         producer o1=new producer(n);
         consumer o2=new consumer(n);  
         o1.start();
         o2.start();    
    }
    
}
