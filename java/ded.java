import java.util.*;
class Main{
    public static void main(String[] args){
            Scanner sc=new Scanner(System.in);
            long m=sc.nextInt();
            long k=1000000;
            for(int i=0;i<m;i++){
                m=sc.nextInt();
                if(m==1){
                    System.out.println("-1\n");
                }
                else if(m<=k){
                    System.out.println(1+" "+1+" "+(m-1));
                    
                }
                else if(m%k==0){
                    System.out.println(((m/k)-1)+" "+k+" "+k);
                }
                else
                System.out.println((m/k)+" "+k+" "+m%k);
            }
    }
}