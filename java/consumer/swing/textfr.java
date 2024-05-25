import java.awt.*;

 class textfr extends Frame {
    public static void main(String[] Args){
      new textfr();
    }
    textfr(){
        TextField emailTextField = new TextField();
        setLayout(new GridLayout(2,1));
        add(emailTextField);
        TextField passwordTextField = new TextField();
        passwordTextField.setEchoChar('*');
        add(passwordTextField);
        String userEmail = emailTextField.getText();
        
        String userpassword = passwordTextField.getText();
        System.out.println(userEmail+" "+userpassword);
       setSize(500,500);
       setVisible(true);
    }

}
