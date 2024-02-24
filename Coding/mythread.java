import java.util.*;
public class mythread extends Thread
{   int n;
    mythread(int n){
        this.n=n;
    }
	public void run(){
     System.out.println("Thread is alive :: "+Thread.currentThread().isAlive());
      for(int i=0;i<n;i++){
        System.out.println("Thread = "+(i+1));
       }
  	}
	public static void main(String[] args)
	{ 
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
		mythread o1=new mythread(n);
        o1.start();
        try{
            o1.join();
            System.out.println("END OF = Thread");
            System.out.println("Thread is alive = "+o1.isAlive());
        }
        catch(Exception o){}
        System.out.print("End of main.");
	}
}