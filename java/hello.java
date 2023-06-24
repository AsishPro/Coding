import java.util.Scanner;

class hello{
    public static void func(){
        System.out.println("Enter the Number to check : ");
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        if(a==2)
        System.out.println("yes");
        else
        System.out.println("no");
    }
}