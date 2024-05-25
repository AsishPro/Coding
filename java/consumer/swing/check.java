import java.awt.*;
import java.awt.event.*;

public class check {
    public static void main(String[] args){
        Frame o1=new Frame("This is a List test");
        // o1.setLayout(null);
        CheckboxGroup k=new CheckboxGroup();
        
        Checkbox o2=new Checkbox("one",true,k);
        o2.setBounds(100, 100, 20, 20);
        o1.add(o2);
        Checkbox o3=new Checkbox("two",false,k);
        o1.add(o3);        
        o1.setSize(500,500);
        o1.setVisible(true);
    }
}
