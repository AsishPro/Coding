import javax.swing.*;
import javax.swing.border.LineBorder;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CRC2 {
    public static void main(String[] args) {
            JFrame frame = new JFrame("CRC Generator");
            frame.setSize(400, 300);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

            JPanel panel = new JPanel();
            frame.add(panel);
            placeComponents(panel);

            frame.setVisible(true);
        
    }

    private static void placeComponents(JPanel panel) {
        panel.setLayout(null);

        JLabel inputLabel = new JLabel("Enter data:");
        inputLabel.setBounds(10, 20, 80, 25);
        panel.add(inputLabel);

        JTextField inputData = new JTextField(20);
        inputData.setBounds(120, 20, 165, 25);
        panel.add(inputData);

        JLabel polynomialLabel = new JLabel("Enter generator:");
        polynomialLabel.setBounds(10, 50, 120, 25);
        panel.add(polynomialLabel);

        JTextField polynomialData = new JTextField(20);
        
        polynomialData.setBounds(120, 50, 165, 25);
        panel.add(polynomialData);

        JButton generateButton = new JButton("Generate CRC");
        generateButton.setBackground(Color.lightGray); 
        generateButton.setBounds(120, 80, 150, 25);
        panel.add(generateButton);

        JLabel crcLabel = new JLabel("CRC:");
        crcLabel.setBounds(10, 120, 80, 25);
        panel.add(crcLabel);

        JTextArea crcArea = new JTextArea();
        crcArea.setBounds(120, 120, 250, 25);
        crcArea.setEditable(false);
        panel.add(crcArea);

        JLabel codewordLabel = new JLabel("Codeword:");
        codewordLabel.setBounds(10, 150, 80, 25);
        panel.add(codewordLabel);

        JTextArea codewordArea = new JTextArea();
        codewordArea.setBounds(120, 150, 250, 25);
        codewordArea.setEditable(false);

         // Light gray background color
        panel.add(codewordArea);

        generateButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String input = inputData.getText();
                String polynomial = polynomialData.getText();

                if (!input.isEmpty() && !polynomial.isEmpty()) {
                    String temp = input;
                    input = rem2.dividend(input, polynomial);
                    rem2 o1 = new rem2(input, polynomial);
                    String crc = o1.crc(0);
                    crcArea.setText(crc);

                    String codeword = temp + crc;
                    codewordArea.setText(codeword);
                    crcArea.setBorder(new LineBorder(Color.BLACK));
                    codewordArea.setBorder(new LineBorder(Color.BLACK));
              
                } else {
                    JOptionPane.showMessageDialog(null, "Please enter data and polynomial");
                }
            }
        });
    }
}
