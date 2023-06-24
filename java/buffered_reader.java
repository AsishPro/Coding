import java.io.*;
import java.util.*;

public class buffered_reader {
    public static void main(String[] args)throws IOException{
    FileReader f1=new FileReader("srm.txt");
    BufferedReader in=new BufferedReader(f1);
    Scanner sc=new Scanner(System.in);
    int count=0;
    String ch=in.readLine();
    while(ch!=null){
        System.out.println(ch); 
        ch=in.readLine();     
    }
    }
}
