import java.util.*;
public class remainder{
    String A;
    String B;
    int index;
    String result;
    remainder(String A,String B){
        this.A=A;
        this.B=B;
        this.index=0;
        this.result="";
    }
    int reset(){
        int c=0;
        for(int i=0;i<result.length();i++){
            if(result.charAt(i)=='1')
                break;
            else
                c++;
        }
        result=result.substring(c,result.length());
        return c;
    }
    void rem(int index){
        int k=B.length();
        result=A.substring(0,k);
        int j=k; 
        for(int i=0;i<A.length();){
            String temp="";
            for(int z=0;z<k;z++){
                temp+=result.charAt(z)^B.charAt(z);
                System.out.println(temp);
            }
            result=temp;
            int add=reset();
            result+=A.substring(j,Math.min(A.length(),j+add));
            j+=add;
        }             
        System.out.print(result); 
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String A=sc.nextLine();
        String B=sc.nextLine();
        remainder o1=new remainder(A,B);
        o1.rem(0);
    }
}
