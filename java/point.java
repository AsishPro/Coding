import java.util.Scanner;
import java.lang.Math;

public class point {
    public static void main(String[] args){
        double x,y;
        Scanner s=new Scanner(System.in);
        System.out.print("Enter the Value of x,y co-ordinates :");
        x=s.nextDouble();
        y=s.nextDouble();
        //rad=10
        double d=Math.sqrt((x)*(x)+(y)*(y));
        System.out.print(d);
        if(d<=10)
        System.out.print("Given point ("+x+","+y+") is in the circle");
        else
        System.out.print("Given point ("+x+","+y+") is not in circle");
    }
}
