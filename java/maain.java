import java.util.*;
class Account{
    protected String accountno,name;
    protected double balance;
}
class savingaccount extends Account{
    protected double minimumbal;

}
class fixedaccount extends savingaccount{
    private int lockingPeriod;
    void setlockingperiod(int t){
        lockingPeriod=t;
    }
    int getlockingperiod(){
        return lockingPeriod;
    }
}

class AccountBO {
    public void getAccountDetail(String Detail){
       String[] splited=Detail.split(",");
       fixedaccount o1=new fixedaccount();
       o1.accountno=splited[0];
       o1.balance=Double.parseDouble(splited[1]);
       o1.name=splited[2];
       o1.minimumbal=Double.parseDouble(splited[3]);
       o1.setlockingperiod(Integer.parseInt(splited[4]));
       int lock=o1.getlockingperiod();
       System.out.format("%-20s %-10s %-20s %-20s %s\n","Account Number","Balance","Account holder name","Minimum balance","Locking period");
       System.out.format("%-20s %-10s %-20s %-20.3s %d\n",o1.accountno,o1.balance,o1.name,o1.minimumbal,lock);
    }
    
}
class maain{
    public static void main(String[] args){
        AccountBO o1=new AccountBO();
        Scanner sc=new Scanner(System.in);
       String s=sc.nextLine();
        o1.getAccountDetail(s);
    }
}

