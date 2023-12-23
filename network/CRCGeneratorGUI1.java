import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CRCGeneratorGUI1 {
    public static void main(String[] args) {
        JFrame frame = new JFrame("CRC Generator");
        frame.setSize(400, 200);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);

        JLabel inputLabel = new JLabel("Enter data:");
        inputLabel.setBounds(10, 20, 80, 25);
        frame.add(inputLabel);

        JTextField inputData = new JTextField(20);
        inputData.setBounds(100, 20, 165, 25);
        frame.add(inputData);

        JLabel polynomialLabel = new JLabel("Enter polynomial:");
        polynomialLabel.setBounds(10, 50, 120, 25);
        frame.add(polynomialLabel);

        JTextField polynomialData = new JTextField(20);
        polynomialData.setBounds(140, 50, 165, 25);
        frame.add(polynomialData);

        JButton generateButton = new JButton("Generate CRC");
        generateButton.setBounds(10, 80, 150, 25);
        frame.add(generateButton);

        JTextArea resultArea = new JTextArea();
        resultArea.setBounds(10, 110, 350, 40);
        resultArea.setEditable(false);
        resultArea.setBackground(new Color(240, 240, 240)); // Light gray background
        resultArea.setForeground(new Color(34, 139, 34)); // Dark green text color
        resultArea.setFont(new Font("Arial", Font.PLAIN, 14));
        frame.add(resultArea);

        generateButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String input = inputData.getText();
                String polynomial = polynomialData.getText();

                if (!input.isEmpty() && !polynomial.isEmpty()) {
                    String temp = input;
                    input = rem2.dividend(input, polynomial);
                    rem2 o1 = new rem2(input, polynomial);
                    String crc = o1.crc(0);
                    resultArea.setText("CRC: " + crc + "\nCodeword: " + temp + crc);

                    // Fade effect (change background color gradually)
                    Timer timer = new Timer(50, new ActionListener() {
                        float alpha = 1.0f;

                        @Override
                        public void actionPerformed(ActionEvent e) {
                            alpha -= 0.05f;
                            if (alpha <= 0.0f) {
                                ((Timer) e.getSource()).stop();
                                alpha = 1.0f;
                            }
                            resultArea.setBackground(new Color(240, 240, 240, Math.max(0, Math.min(255, (int) (255 * alpha)))));
                        }
                    });
                    timer.start();
                } else {
                    JOptionPane.showMessageDialog(null, "Please enter data and polynomial");
                }
            }
        });

        frame.setVisible(true);
    }
}
