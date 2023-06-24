import java.text.SimpleDateFormat;
import java.util.*;
import java.util.concurrent.TimeUnit;

abstract class Accot {
    String name;
    int id,balance;
    int calculate_time(String s,String e){
        try {
            SimpleDateFormat sdf = new SimpleDateFormat("dd/mm/yyyy");
                Date start = sdf.parse(s);
                Date end = sdf.parse(e);
                long timeDiff = Math.abs(start.getTime() - end.getTime());
                long daysDiff = TimeUnit.DAYS.convert(timeDiff, TimeUnit.MILLISECONDS);
                return (int)(daysDiff/365);
            }
            catch(Exception en){
                System.out.print("Error");
            }
            return 0;
     }
     abstract void calculateInterest(int time);
}

class CurrentAccount extends Accot{
    CurrentAccount(String name,int num,int bal){
        this.name=name;
        balance=bal;
        id=num;
    }
   void calculateInterest(int time){
    System.out.println(balance*(5/100.0)*time);
   }
}
class SavingsAccount extends Accot{
    SavingsAccount(String name,int num,int bal){
        this.name=name;
        id=num;
        balance=bal;
    }
    void calculateInterest(int time){
        System.out.println(balance*(12/100.0)*time);
  }
}
class date{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int ch=sc.nextInt();
        String name=sc.next();
        int num=sc.nextInt();
        int bal=sc.nextInt();
        String a=sc.next();
        String b=sc.next();
        if(ch==1){
            SavingsAccount o1=new SavingsAccount(name,num,bal);
            int t=o1.calculate_time(a,b);
            o1.calculateInterest(t);
        }
        else{       
            CurrentAccount o1=new CurrentAccount(name,num,bal);
            int t=o1.calculate_time(a,b);
            o1.calculateInterest(t);
        } 
    }
}
