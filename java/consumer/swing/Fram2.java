import java.awt.Color;
import java.awt.Container;

import javax.swing.*;
public class Fram2 extends JFrame{
    public static void main(String[] args){
        Fram2 o1=new Fram2();
        o1.setTitle("Test");  //but have to set name like this
        Container c=o1.getContentPane();
        c.setBackground(Color.CYAN);
        
        o1.setVisible(true);
        o1.setSize(400,500); 

        //inside value is constant which indicates what to do
        o1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 

        
    }
}