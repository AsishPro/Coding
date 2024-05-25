import java.awt.Color;
import java.awt.Font;
import java.awt.print.Book;

import javax.swing.*;
import javax.swing.border.Border;

public class label {
    public static void main(String[] args){
        
        Border b1=BorderFactory.createLineBorder(Color.green,10); //border class color,thickness

        ImageIcon i0=new ImageIcon("images.png");
       
        JLabel l1=new JLabel("This is a Text label"); 
        //l1.setText("This is a Text");
        l1.setIcon(i0);
        l1.setForeground(Color.black);  //used for changing font color
        l1.setFont(new Font("Calibri",Font.BOLD,23)); //have to give 3 parameters
        l1.setIconTextGap(15);  //sets gap b/w text and image can also be -ve

        l1.setBackground(Color.yellow);  //label takes all frame because of default layout manager
        l1.setOpaque(true);  //tells to override color set by parent class(Jframe)
        l1.setBorder(b1);
       
        
        
        // l1.setHorizontalTextPosition(JLabel.CENTER); 
        // //sets text left,right,center of image icon doesnt work if no image

        // // l1.setVerticalTextPosition(JLabel.TOP);  //top,center,bottom
        // l1.setHorizontalAlignment(JLabel.CENTER); //sets horizontal postion icon+text alignment of label
        // // l1.setBounds(60,50, 350, 350);  //x,y width,height . x,y indicate top left or location and w,h indicate size of label
    

        

        JFrame o1=new JFrame("label_test"); //obj or instance
        // o1.setLayout(null);
        o1.setSize(600,600);
        o1.setVisible(true);
        o1.getContentPane().setBackground(Color.black);
        System.out.print(o1.isVisible());
        ImageIcon i1=new ImageIcon("image.jpg");
        o1.setIconImage(i1.getImage());
        o1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        o1.add(l1); //adds the created label container to JFrame 
        // o1.pack(); sets frame size to size of all components
    }
}
