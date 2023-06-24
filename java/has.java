
import java.util.*;
class has{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        String s1=sc.nextLine();
        String[] a=s.split(" ");
        String[] b=s1.split(" ");
        HashSet<String> hs=new HashSet<String>(Arrays.asList(a));
        HashSet<String> h2=new HashSet<String>(Arrays.asList(b));
        hs.retainAll(h2);
        System.out.print(hs);
    }
}
