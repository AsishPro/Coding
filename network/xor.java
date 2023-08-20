import java.util.*;
public class xor{
    public static String or(String a,String b){
        String res="";
        if(a.length()!=b.length())
        return "-1";
        else{ 
            for(int i=0;i<a.length();i++){
                res+=(a.charAt(i)-48)^(b.charAt(i)-48);  //converting to int and then xor else we can directly use chars
            }
        }
        return res;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String a=sc.nextLine();
        String b=sc.nextLine();
        System.out.print(xor.or(a,b));
        

    }
}