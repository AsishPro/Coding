import java.awt.Color;
import java.awt.Container;
import java.lang.reflect.InaccessibleObjectException;

import javax.swing.*;


class img{
    public static void main(String[] args){
        JFrame o1=new JFrame();
        ImageIcon i1=new ImageIcon("image.jpg");
        o1.setIconImage(i1.getImage());
        
        o1.setVisible(true);
        o1.setSize(400,500); 

        //inside value is constant which indicates what to do
        o1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 

        
    }
}