import java.util.*;
class ticket extends Thread{
    int t=1;
    synchronized public void run(){
        t=t-1;
        System.out.println(t);
    }

}
public class maaain {
    public static void main(String[] args)throws InterruptedException{
       ticket o=new ticket();
       Thread o1=new Thread(o);
       Thread o2=new Thread(o);
       o1.start();
       o2.start();
    }
}

