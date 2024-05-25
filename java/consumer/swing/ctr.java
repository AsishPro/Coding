
import javax.swing.*;
import java.awt.*;
class ctr extends JFrame {
    public static void main(String[] args){
        ctr o1=new ctr();
        JButton j=new JButton("Asish");
        JPanel panel = new JPanel();
        j.setPreferredSize(new Dimension(100,100));
        panel.add(j);
        o1.add(panel);
        // o1.setLayout(new FlowLayout(FlowLayout.CENTER));
        o1.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // o1.add(j);
        o1.setSize(500,500);
        o1.setVisible(true);    
    }
}
