import java.io.*;
import java.net.*;

public class TCPClient0 {
    public static void main(String[] args){
        try{
            Socket ss=new Socket("localhost",6666);
            DataInputStream di=new DataInputStream(ss.getInputStream());
            String s=di.readUTF();
            System.out.println(s);
            
        }
        catch(Exception e){
            System.out.println(e);
        }

    }
}
