import javax.swing.*;
import java.awt.*;

class calc  extends JFrame {
    private JLabel l1,l2,r1;
    private JTextField t1,t2;
    private JButton b1,b2;
    public calc(){
      setName("Calculator");
      setLayout(new FlowLayout());
      l1=new JLabel("num1: ");
      add(l1);
      t1=new JTextField(20);
      add(t1);
      System.out.print(t1.getText());
      l2=new JLabel("num2: ");
      add(l2);
      t2=new JTextField("Hello",2);
      add(t2);
      
      
      setVisible(true);
      setSize(400,100);
      setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}
class calculator{
    public static void main(String[] args){
        calc o1=new calc();
    }
}
