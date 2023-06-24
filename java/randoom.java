import java.lang.Math;
import java.util.Scanner;

public class randoom {
    public static void main(String[] args){
/*math.random gives in [0,1) double values, so multiplying with required range(2 max-min)
here 0,1,2 gives values upto [0,2) but one more is needed 2 so adding 1 and typecasting to integers. */ 
        int r=(int)(Math.random()*(3));

        Scanner s=new Scanner(System.in);
        int x=5;  //random initialized
        //until input not 4
    while(x!=4){
        r=(int)(Math.random()*(3));
        System.out.println("\n0 - Scissor\n1 - Rock\n2 - Paper \nSelect the number: ");
        x=s.nextInt();
     if(r==x){
        if(r==0)
        System.out.println("Computer is Scissor. You are Scissor. Draw ");
        else if(r==1)
        System.out.println("Computer is Rock. You are Rock. Draw ");
        else 
        System.out.println("Computer is Paper.You are Rock. Draw ");
     }
     else{
       if(r==0 && x==1)
       System.out.println("Computer is Scissor. You are Rock. You Win");
       if(r==0 && x==2)
       System.out.println("Computer is Scissor.You are Paper.Computer Win");

       if(r==1 && x==2)
       System.out.println("Computer is Rock. You are Paper. You Win");
       if(r==1 && x==0)
       System.out.println("Computer is Rock.You are Scissor.Computer Win");

       if(r==2 && x==0)
       System.out.println("Computer is Rock. You are Scissor. You Win");
       if(r==2 && x==1)
       System.out.println("Computer is Rock. You are Paper. Computer Wins");
      }
     }
  }
}
