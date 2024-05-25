import java.awt.*;

public class choice extends Frame {
    public static void main(String[] Args){
      new choice();
    }
    choice(){
       Choice c=new Choice();
       c.setBounds(100,100,20,20);
       c.add("One");
       c.add("Tw0");
       c.add("Three");
       add(c);
       setSize(500,500);
       setVisible(true);
    }

}
