import java.util.Scanner;

class Addamount {
    int amount=50;
    Addamount(){
        System.out.println(amount);
    }
    Addamount(int k){
         amount+=k;
         System.out.println(amount);
    }
    public static void main(String[] args){
        Addamount o1=new Addamount();
        Scanner sc=new Scanner(System.in);
        int add=sc.nextInt();
        Addamount o2=new Addamount(add);
    }
}

