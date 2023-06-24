import java.util.Scanner;

class offici {
    void func(){
        System.out.println("Enter the Number to check : ");
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        if(a==2)
        System.out.println("yes");
        else
        System.out.println("no");
    }
    public static void main(String[] args){
       Scanner in=new Scanner(System.in);
       String name=in.nextLine();
       int age=in.nextInt();
       char ch=in.next().charAt(0);
       System.out.println(name.charAt(0));
       System.out.println(age);
       System.out.println(ch);
       offici ob=new offici();
       ob.func();
    }
    
}
