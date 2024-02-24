import java.util.*;

public class stack {
    public static void main(String[] args){
        Stack <Integer> o=new Stack<Integer>();
        Scanner sc=new Scanner(System.in);
        
        while(true){
        System.out.println("1.PUSH\n2.POP\n3.Search\n4.Display: ");
        int ch=sc.nextInt();
        if(ch==1){
        System.out.print("Enter the element to add: ");
        int n=sc.nextInt();
        o.add(n);
        }
        else if(ch==2){
            o.remove((Integer)4); 
        }
        else if(ch==3){
            System.out.print("Enter the element to seach: ");
            int n=sc.nextInt();
           
            System.out.println("Index: "+o.search(n)); //works from top to bottom 
        }
        else if(ch==4)
        System.out.println(o);
        else System.out.println("Enter VAlid choice");
      }
    }
}
