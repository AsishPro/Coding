import java.util.*;
class occurance {
    public static void main(String[] args){
        int a[]=new int[100];
        Scanner sc=new Scanner(System.in);
        int x;
         while(true){
            x=sc.nextInt();
            if(x==0)
            break;
            a[x]++;
         }
         for(int i=0;i<100;i++){
            if(a[i]!=0 )
               System.out.println(i+" occurs "+a[i]+(a[i]>1?" times":" time"));
         }
    }
}
