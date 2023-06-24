import java.io.*;
class Reserve extends Thread
{
int available=1;
int wanted;
Reserve(int i)
{
wanted=i;
}
public void run()
{
synchronized(this)
{
System.out.println("Available berths="+available);
if(available>=wanted)
{
String name=Thread.currentThread().getName();
System.out.println(wanted+"Berths Reserved for"+name);
try
{
Thread.sleep(2000);
available=available-wanted;
}catch(InterruptedException ie)
{
ie.printStackTrace();
}
}
else 
System.out.println("Sorry no berths");
}
}
}
class sync
{
public static void main(String args[])
{
Reserve obj=new Reserve(1);
Thread t1=new Thread(obj);
Thread t2=new Thread(obj);
t1.setName("First Person");

t1.start();

t2.setName("Second Person");
t2.start();
}
}