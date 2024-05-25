import javax.swing.*;
public class Framee{
    public static void main(String[] args){
        JFrame o1=new JFrame("asish");
        //either create like this or directly extend Jframe class

        o1.setVisible(true);  //display the frame
        o1.setSize(400,500);  // width,height
 
        //inside value is constant which indicates what to do
        o1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
    }
}












       
        // while(true){
        //     try{
        //     Thread.sleep(10000);
        //     }
        //     catch(Exception e){
        //     }
        //     o1.setVisible(false);
        // }