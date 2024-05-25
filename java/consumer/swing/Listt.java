import java.awt.*;
import java.awt.event.*;

public class Listt {
    public static void main(String[] args){
        Frame o1=new Frame("This is a List test");
        // o1.setLayout(new FlowLayout());
         o1.setLayout(null);
        List l1=new List(20);
        l1.add("Test");
        l1.add("String");
        for(int i=0;i<10;i++){
            l1.add(i+" ");
        }
        l1.setBounds(50,50,150,150);
        
        l1.addItemListener(new ItemListener() {
            public void itemStateChanged(ItemEvent e){
                if(e.getStateChange()==1)
                System.out.print(l1.getSelectedItem());
            }
        });
        
        String selectedItem = l1.getSelectedItem();
        System.out.println("Selected item: " + selectedItem);o1.add(l1);
        o1.setSize(500,500);
        o1.setVisible(true);
    }
}
