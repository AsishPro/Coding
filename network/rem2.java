import java.util.*;
public class rem2{
    String s;
    String b;
    int index;
    String res;
    rem2(String s,String b){
        this.s=s;
        this.b=b;
        this.index=0;
        this.res="";
    }
    int reset(){
        int c=0;
            while(c<res.length() && res.charAt(c)!='1'){
                c++;
            }
        res=res.substring(c,res.length());
        return c;
    }
    String crc(int index){
        int k=b.length();
        res=s.substring(0,k);
        int j=k;
        while(j<=s.length()){ 
            String temp="";
            for(int i=0;i<k;i++){
                temp+=res.charAt(i)^b.charAt(i);
            }  
            res=temp;
            int add=reset();
            res+=s.substring(j,Math.min(s.length(),j+add));
            j+=add;
        }             
        return res;
    }
    static String dividend(String s,String b){
        for(int i=0;i<b.length()-1;i++){
            s+="0";
        }
        return s;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        String b=sc.nextLine();
        String temp=s;
        s=rem2.dividend(s, b);
        rem2 o1=new rem2(s,b);
        String crc=o1.crc(0);
        System.out.println("crc: "+crc);
        System.out.println("codeword :"+temp+crc);
    }
}
