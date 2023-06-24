import java.awt.*;
import java.awt.event.*;

class color extends Frame implements ActionListener {
    Button b1, b2, b3;

    color(){
        this.setLayout(null);
        b1 = new Button("Red");
        b2 = new Button("Green");
        b3 = new Button("Blue");

        b1.setBounds(100, 100, 70, 40);
        b2.setBounds(100, 150, 70, 40);
        b3.setBounds(100, 200, 70, 40);

        this.add(b1);
        this.add(b2);
        this.add(b3);

        b1.addActionListener(this);
        b2.addActionListener(this);
        b3.addActionListener(this);

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public void actionPerformed(ActionEvent ae) {
        String s = ae.getActionCommand();
        if (s.equals("Red"))
            this.setBackground(Color.red);
        if (s.equals("Green"))
            this.setBackground(Color.green);
        if (s.equals("Blue"))
            this.setBackground(Color.blue);
    }

    public static void main(String args[]) {
        color f = new color();
        f.setSize(400, 400);
        f.setTitle("My Buttons with Color");
        f.setVisible(true);
    }
}