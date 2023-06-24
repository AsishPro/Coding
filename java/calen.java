// You are using Java
import java.util.*;
class calen{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int d,m;
        d=sc.nextInt();
        m=sc.nextInt();
        if(d<1||d>31||m<1||m>12)
        System.out.println("Invalid Date/Month");
        else{
            System.out.print("Astrological sign for ");
            if( (m==1 && d>=20) || (m==2 && d<=18))
            System.out.println(d+"-"+m+" is Aquarius");
            else if( (m==2 && d>=19) || (m==3 &&d<=20))
            System.out.println(d+"-"+m+" is Pisces");
            else if((m==3 && d>=21) || (m==4 && d<=19))
            System.out.println(d+"-"+m+" is Aries");
            else if((m==4 && d>=20) || (m==5 && d<=20))
            System.out.println(d+"-"+m+" is Taurus");
            else if((m==5 && d>=21) || (m==6 && d<=20))
            System.out.println(d+"-"+m+" is Gemini");
            else if((m==6 && d>=21) || (m==7 && d<=22))
            System.out.println(d+"-"+m+" is Cancer");
            else if((m==7 && d>=23) || (m==8 && d<=22))
            System.out.println(d+"-"+m+" is Leo");
            else if((m==8 && d>=23) || (m==9 && d<=22))
            System.out.println(d+"-"+m+" is Virgo");
            else if((m==9 && d>=23) || (m==10 && d<=22))
            System.out.println(d+"-"+m+" is Libra");
            else if((m==10 && d>=23) || (m==11 && d<=21))
            System.out.println(d+"-"+m+" is Scorpio");
            else if((m==11 && d>=22)||(m==12 && d<=21))
            System.out.println(d+"-"+m+" is Sagittarius");
            else 
            System.out.println(d+"-"+m+" is Capricorn");
        }
    }
}