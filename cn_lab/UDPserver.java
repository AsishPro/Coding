import java.net.*;

public class UDPserver {
    public static void main(String[] args){
        try{
            DatagramSocket socket=new DatagramSocket(6666);
            byte[] receivedata=new byte[1024];
            while(true){
                DatagramPacket packet=new DatagramPacket(receivedata,receivedata.length);
                // receive into packet
                socket.receive(packet);
                // convert
                String message= new String(packet.getData(),0,packet.getLength());
                System.out.print(message);

                String reply="Hi Client!";
                byte[] senddata=reply.getBytes();
                InetAddress cip=packet.getAddress();
                int port=packet.getPort();

                DatagramPacket senpacket=new DatagramPacket(senddata,senddata.length,cip,port);
                socket.send(senpacket);
                System.out.print("Packet Sent!");
            

            }
            
        }
        catch(Exception e){
            System.out.println(e);
        }
    }
}
