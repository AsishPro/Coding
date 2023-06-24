import java.io.*;
class Reserve1 extends Thread
{
//int count=0;
public void run(){
System.out.println(Thread.currentThread().getName());
System.out.println(Thread.currentThread().getPriority());
}
}
class ticket
{
public static void main(String args[])
{
Reserve1 obj=new Reserve1();
Thread t1=new Thread(obj,"one");
Thread t2=new Thread(obj,"two");
t2.setPriority(10);
t1.setPriority(1);

t1.start();
System.out.println("SRM");
t2.start();
}
}