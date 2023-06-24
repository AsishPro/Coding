import java.lang.Exception;

class beta extends Thread
{
    
    public void run()
    {
        try
        {
        for(int i=0;i<5;i++)
        {
        System.out.println("Thread in first class");
        Thread.sleep(1000);
        }
    }
        catch(Exception e){
         System.out.println(e);
        }
    }
    
}
class gamma extends Thread
{
   
    public void run()
    {
        int i=0;
  while(true)
    {
        System.out.println("Thread in 2nd class ");
        i++;
    }
    }
    
}
class peter{
    
    public static void main(String[] args)
    {
        beta b1=new beta();
        b1.start();
        gamma g1=new gamma();
        g1.run();
        g1.start();
       
    }
}