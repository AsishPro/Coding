import java.io.DataInputStream;
import java.net.*;

public class TCPServer2{
    public static void main(String[] args){
        try{
            ServerSocket ss=new ServerSocket(6666);
            Socket s=ss.accept();
            String str="";
            DataInputStream dt=new DataInputStream(s.getInputStream());
            while(!str.equals("stop")){
                // try{
                str=(String)dt.readUTF();
                System.out.println(str);
        
                // System.out.println(e);
                
            }
            ss.close();
            s.close();
            dt.close();
        }
        catch(Exception e){
            System.out.print(e);
        }

    }
}