import java.io.*;
import java.util.*;

public class fileread {
    public static void main(String[] args)throws IOException{
    FileReader f1=new FileReader("srm.txt");
    Scanner sc=new Scanner(System.in);
    char c=sc.next().charAt(0);
    int count=0;
    int ch=f1.read();
    while(ch!=-1){
        if((char)ch==c)
        count+=1; 
        ch=f1.read();      
    }
    System.out.print(count);
    }
}