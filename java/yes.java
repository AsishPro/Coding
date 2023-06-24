import javax.swing.JFrame;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;

 class MyFrames extends JFrame   {
    JButton button;
    MyFrames()
    {

         button=new JButton();
        button.setBounds(200,100,200,50);

        button.addActionListener(e -> System.out.println("You've pressed the button"));
        button.setText("BUTTON");
        button.setFocusable(false); // to get rid of border around text message.
       button.setFont(new Font("Comic Sans", Font.BOLD,16));
       button.setForeground(Color.BLACK);
       button.setBackground(Color.gray);
       button.setBorder(BorderFactory.createEtchedBorder());
        this.setDefaultCloseOperation(javax.swing.JFrame.EXIT_ON_CLOSE);
        this.setLayout(null);
        this.setSize(500,500);
        this.setVisible(true);
        this.add(button);
    }
//     @Override
//    public void actionPerformed(ActionEvent e)
//     {
//         if(e.getSource()==button)
//         {
//             System.out.println("You've clicked Button");
//         }
//     }
    
}
class MyFrame{
    public static void main(String[] args)
    {
MyFrames frame=new MyFrames();
    }
}