import java.util.*;
class Queuesw{
    int x;
    boolean flag =false;
    synchronized int get(){
        while(!flag)
           try{
               wait();
           }catch(InterruptedException e){
               System.out.println("InterruptedException caught");
           }
     System.out.println("Consumer ::: "+x);
     flag=false;
     notify();
     return x;
    }
    synchronized void put(int n){
        while(flag)
        try{
            wait();
        }catch(InterruptedException e){
            System.out.println("InterruptedException caught");
        }
        x=n;
        System.out.println("Producer ::: "+x);
        flag=true;
        notify();
    }
}
class Thread_P extends Thread{
    Queue q;
    int i;
    Thread_P(Queue q)
    {
        this.q=q;
    }
    public void run()
    {
        Scanner sc =new Scanner(System.in);
        int n=Integer.parseInt(sc.nextLine());
        for( i=1;i<=n;i++){
            try{
                Thread.sleep(300);
            }catch( InterruptedException e)
              {  }
              q.put(i );
            
        }
        System.out.println("Producer Terminating. ");
    }
}
class Thread_C extends Thread{
    Queue q;
    Thread_C(Queue q){
        this.q=q;
    }
    public void run()
    {
        int i;
        do
        {
            try
            {
                Thread.sleep(300);
            }catch(InterruptedException e)
            { }
            i=q.get();
        }while(i!=1000);
        System.out.println("Consumer Terminating. ");
    }
}
class copy{
    public static void main(String[] args){
        Queue q=new Queue();
        Thread_P p=new Thread_P(q);
        Thread_C c=new Thread_C(q);
        p.start();
        c.start();
    }
}


