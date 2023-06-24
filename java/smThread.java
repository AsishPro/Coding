class MyThread extends Thread
{
public void run()
{
try
{
for(int i=1;i<10;i++)
{
	System.out.println(i);
Thread.sleep(1100);
}
}catch(InterruptedException e)
{}	
}
}
class smThread
{
public static void main(String args[])
{
MyThread obj1=new MyThread();
Thread t=new Thread(obj1);
t.start();
try
{
for(int i=1;i<10;i++)
{
	System.out.println("Main");
Thread.sleep(1000);
}
}catch(InterruptedException e)
{}
}
}