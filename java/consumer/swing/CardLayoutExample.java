import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class CardLayoutExample extends Frame {

    CardLayout card;
    Button b1, b2, b3;
    Container c;

    CardLayoutExample() {
        setTitle("Card Layout Example");

        card = new CardLayout(40, 30); // create CardLayout object with 40 hor space and 30 ver space

        c = new Panel(); // initialize the container with a panel
        c.setLayout(card);

        b1 = new Button("Apple");
        b2 = new Button("Boy");
        b3 = new Button("Cat");

        c.add("a", b1);
        c.add("b", b2);
        c.add("c", b3);

        add(c, BorderLayout.CENTER); // add the container to the frame
        setSize(400, 400);
        setVisible(true);

        // Add functionality to the buttons to switch between the cards
        b1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                card.show(c, "a");
            }
        });
        b2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                card.show(c, "b");
            }
        });
        b3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                card.show(c, "c");
            }
        });

        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                dispose();
            }
        });
    }

    public static void main(String[] args) {
        new CardLayoutExample();
    }
}