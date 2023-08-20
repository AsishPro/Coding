import java.util.Scanner;
class parity{
public int computeParity(String s){
    int c=0;
    for(int i=0;i<s.length();i++){
        if(s.charAt(i)=='1')
            c++;
    }
    return c%2;
}
public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    String s=sc.nextLine();
    parity o1=new parity();
    System.out.print(o1.computeParity(s));
}
}