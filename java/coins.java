import java.util.Random;

public class coins{
    public static void main(String[] args){

        Random r=new Random();
        //generates 0-12 + 1 inclusive to start from 1-13
        int card;
        int i=0;
        int h=0,t=0;
        while(i<4){
            card=r.nextInt(2);
            if(card==0)
            h++;
            else
            t++;
            i++;           
        }
        System.out.println("The Heads are "+h+" and the percentage ="+((h/4.0)*100));
        System.out.print("The Tails are "+t+" and the percentage ="+((t/4.0)*100));
    }
}
