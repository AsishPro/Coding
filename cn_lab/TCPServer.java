import java.io.*;
import java.net.*;
import java.util.Scanner;

public class TCPServer {
    public static void main(String[] args){
    try{
        ServerSocket ss=new ServerSocket(6666);
        Socket s=ss.accept();
        System.out.println("Connection accepted");
    
        // DataInputStream dt=new DataInputStream(s.getInputStream());
        // String st=(String)dt.readUTF();
        // System.out.println(st);

        DataOutputStream dt2=new DataOutputStream(s.getOutputStream());
        Scanner sc=new Scanner(System.in);
        String str=sc.nextLine();
        dt2.writeUTF(str);
        sc.close();
        dt2.close();
    }
    catch(Exception e){
        System.out.println(e);
    }
        
    }
}
