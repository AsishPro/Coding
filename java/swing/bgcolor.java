import java.awt.Color;
import java.awt.Container;
import javax.swing.*;

class bgcolor{
    public static void main(String[] args){
        JFrame o1=new JFrame();
        o1.setTitle("Test");  //but have to set name like this

        Container c=o1.getContentPane();
        c.setBackground(Color.CYAN);
        o1.getContentPane().setBackground(Color.cyan); //change baground color of baground
        o1.getContentPane().setBackground(new Color(100,100,100)); 

        ImageIcon i1=new ImageIcon("image.jpg");
        o1.setIconImage(i1.getImage()); //change icon of frame
 
        // o1.setResizable(false);
        o1.setVisible(true);
        o1.setSize(400,500); 
        
        //inside value is constant which indicates what to do
        o1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 

        
    }
}