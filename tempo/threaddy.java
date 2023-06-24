import java.util.*;
class t implements Runnable{
    int n;
    t(int n){
    this.n=n;
    }
    public void run(){
      System.out.println("This thread is running "+n);
    }
}
class threaddy{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        for(int i=0;i<n;i++){
           t o1=new t(i+1);
           Thread o2=new Thread(o1);
           o2.start();
        }
        System.out.println("start");
    }
}