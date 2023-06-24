import java.util.Random;
public class cards {
    public static void main(String[] args){

        Random r=new Random();
        //generates 0-12 + 1 inclusive to start from 1-13
        int card=r.nextInt(13)+1;
        
        //0-3 +1 = 1-4 range
        int suit=r.nextInt(4)+1;
        System.out.print("The Card is ");

        if(card==1) System.out.print("Ace");
        else if(card==11) System.out.print("Jack");
        else if(card==12) System.out.print("Queen");
        else if(card==13) System.out.print("King");
        else System.out.print(card);
 
        if(suit==1) System.out.print(" of Clubs");
        if(suit==2) System.out.print(" of Diamonds");
        if(suit==3) System.out.print(" of Hearts");
        if(suit==4) System.out.print(" of Spades");
        
    }
}
