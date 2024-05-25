
import java.awt.Color;
import java.awt.Container;

import javax.swing.*;
public class testttt{
    public static void main(String[] args){
    JFrame o1=new JFrame("This is new window");
    o1.setVisible(true);
    o1.setSize(250,600);
    Container o2=o1.getContentPane();
    o2.setBackground(Color.blue);
    o1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}
