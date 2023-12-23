import java.net.*;

public class UDPclient{
    public static void main(String[] args){
        try{
        DatagramSocket socket=new DatagramSocket();
        String message="Hi UDP Server";
        byte[] senddata=message.getBytes();
        InetAddress ip=InetAddress.getByName("localhost");
        DatagramPacket packet=new DatagramPacket(senddata,senddata.length,ip,6666);
        socket.send(packet);
        System.out.println("Packet sent!");
        
        byte[] recievedata=new byte[1024];
        DatagramPacket receivepacket=new DatagramPacket(recievedata,recievedata.length);
        socket.receive(receivepacket);
        String reply=new String(receivepacket.getData(),0,receivepacket.getLength());
        System.out.println(reply);
        }
        catch(Exception e){
            System.out.print(e);
        }
    }
}