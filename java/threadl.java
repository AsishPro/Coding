class A extends Thread{
    String a;
    A(String s){
    a=s;
    }
    synchronized public void run(){
    try{
    for(int i=0;i<5;i++){
     System.out.println(a+" "+i);
     Thread.sleep(100);
    }
   }catch(InterruptedException o1){

   }
}
}
class threadl{
   public static void main(String[] args){
    A o1=new A("Asus");
    // A o2=new A("ROG");
     Thread o=new Thread(o1);
     Thread o2=new Thread(o1);
     o2.start();
    o.start();

   }
}  
