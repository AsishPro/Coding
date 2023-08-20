import java.util.*;
public class codeword{
    public static int CodewordCheck(String a,String b){
        int c=0;
        if(a.length()!=b.length())
        return -1;
        else{ 
            for(int i=0;i<a.length();i++){
                if(a.charAt(i)!=b.charAt(i))
                    c+=1;
            }
        }
        return c;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String a=sc.nextLine();
        String b=sc.nextLine();
        System.out.print(codeword.CodewordCheck(a,b));
        

    }
}