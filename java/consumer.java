import java.util.*;
class producer implements Runnable{
    private final int threadnumber;

    MyRunnable(int threadnumber){
        this.threadnumber = threadnumber;
    }
    public void run() {
        System.out.println(threadnumber);
    }
}
class consumer{
    public static void main(String[] args) {
        for(int i=1; i<=10; i++){
            MyRunnable o1=new MyRunnable(i);
            Thread o2=new Thread(o1);
            o2.start();
            try{
                o2.join();
            }   
            catch(Exception o){
                System.out.print(o);
            }      
        }
    }
}
