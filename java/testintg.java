
class B implements Runnable {  
    public void run(){
       try{
        for(int i=0;i<10;i++){
            System.out.println("in B");
            Thread.sleep(1000);
        }
       }
       catch(InterruptedException o1){
         System.out.print(o1);
       }
    }
}
class testintg{
    public static void main(String[] ars){
       B o1=new B();
       Thread t=new Thread(o1);
       t.start();
       t.setPriority(10);
       System.out.print(t.getName()+" ");
       try{
       for(int i=0;i<20;i++){
       System.out.println("Asish");
       Thread.sleep(1000);
       }
    }
    catch(InterruptedException e){
        System.out.print(e);
    }
    }
}