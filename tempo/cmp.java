import java.util.*;
public class cmp{
   public static void main(String[] args){
       HashSet <String> hs= new HashSet<String>();
       hs.add("Asish");
       hs.add("wtf");
       hs.add("how");
       hs.add("to do");
       System.out.println(hs);
       Iterator it=hs.iterator();
       while(it.hasNext()){
         String s=(String)it.next();
         System.out.println(s);
       }

   }
}
