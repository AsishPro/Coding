import java.io.*;
import java.net.*;
import java.util.Scanner;
public class TCPClient {
    public static void main(String[] args){
        try{
        Socket s=new Socket("localhost",6666);
        // DataOutputStream dt=new DataOutputStream(s.getOutputStream());
        // dt.writeUTF("hi asish message");
        // dt.writeUTF("hi this is second line");
        DataOutputStream dt2=new DataOutputStream(s.getOutputStream());
        Scanner sc=new Scanner(System.in);
        while (true) {
            String str=sc.nextLine();
            dt2.writeUTF(str);
        }
    
        }
        catch(Exception e){
            System.out.print(e);
        }
    }
}
