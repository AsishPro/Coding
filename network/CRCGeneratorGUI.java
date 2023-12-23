    import javax.swing.*;
    import java.awt.event.ActionEvent;
    import java.awt.event.ActionListener;

    public class CRCGeneratorGUI {
        public static void main(String[] args) {
            JFrame frame = new JFrame("CRC Generator");
            frame.setSize(400, 200);
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
            inputData.setBounds(100, 20, 165, 25);
            panel.add(inputData);

            JLabel polynomialLabel = new JLabel("Enter polynomial:");
            polynomialLabel.setBounds(10, 50, 120, 25);
            panel.add(polynomialLabel);

            JTextField polynomialData = new JTextField(20);
            polynomialData.setBounds(140, 50, 165, 25);
            panel.add(polynomialData);

            JButton generateButton = new JButton("Generate CRC");
            generateButton.setBounds(10, 80, 150, 25);
            panel.add(generateButton);

            JTextArea resultArea = new JTextArea();
            resultArea.setBounds(10, 110, 350, 40);
            resultArea.setEditable(false);
            panel.add(resultArea);  

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
                    } else {
                        JOptionPane.showMessageDialog(null, "Please enter data and polynomial");
                    }
                }
            });
        }
    }
