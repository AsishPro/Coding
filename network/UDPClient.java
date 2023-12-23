import java.net.*;

public class UDPClient {
    public static void main(String[] args) {
        try {
            DatagramSocket socket = new DatagramSocket();
            InetAddress serverAddress = InetAddress.getByName("localhost");
            String message = "Hello Server";
            byte[] sendData = message.getBytes();word

            DatagramPacket sendPacket = new DatagramPacket(sendData, sendData.length, serverAddress, 6666);
            socket.send(sendPacket);

            System.out.println("Message sent to server: " + message);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
