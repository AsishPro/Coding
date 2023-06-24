import java.util.*;
import java.text.SimpleDateFormat;
import java.util.concurrent.TimeUnit;
import java.lang.Exception;

import javax.crypto.spec.DESKeySpec;
public class date {
    void dat(String s,String e){
        try{
            SimpleDateFormat obj=new SimpleDateFormat("dd/mm/yyyy");
            Date o1=obj.parse(s);
            Date o2=obj.parse(e);
            long seconds=Math.abs(o1.getTime()-o2.getTime());
            double days=TimeUnit.DAYS.convert(seconds,TimeUnit.MILLISECONDS);
            System.out.print(days);
           
        }
        catch(Exception k ){

        }
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        String e=sc.nextLine();
        date k=new date();
        k.dat(s, e);
    }
}
