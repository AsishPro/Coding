// You are using Java
import java.util.*;
class Hashset{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String s1=sc.nextLine();
        String s2=sc.nextLine();
        String a1[]=s1.split(" ");
        String a2[]=s2.split(" ");
        HashSet<String> h1=new HashSet<String> (Arrays.asList(a1));
        HashSet<String> h2=new HashSet<String> (Arrays.asList(a2));
        System.out.println(h1);
        System.out.println(h2);
        ArrayList<String>temp=new ArrayList<String>();
        for(String k:h1){
            if(h2.contains(k))
               temp.add(k);
        }
        System.out.print(temp);
    }
}