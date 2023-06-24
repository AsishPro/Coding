import java.io.*;
class Producer extends Thread
{
StringBuffer sb;
boolean dataprodover=false;
Producer()
{
sb=new StringBuffer();
}
public void run()
{
for(int i=1;i<=10;i++)
{
try
{
sb.append(i+":");
Thread.sleep(100);
System.out.println("Appending");
}catch(InterruptedException ie)
{
ie.printStackTrace();
}
}
dataprodover=true;
System.out.print(dataprodover);
}
}
class Consumer extends Thread
{
Producer prod;
Consumer(Producer prod)
{
this.prod=prod;
}
public void run()
{
try
{
while(!prod.dataprodover)
Thread.sleep(1);
System.out.println("Appending11l");
}catch(InterruptedException ie)
{
ie.printStackTrace();
}
System.out.println(prod.sb+"yes");
}
}

class communicate
{
public static void main(String args[])
{
Producer obj1=new Producer();
Consumer obj2=new Consumer(obj1);
Thread t1=new Thread(obj1);
Thread t2=new Thread(obj2);
t1.start();
t2.start();
}
}