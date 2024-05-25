import java.awt.*;

public class awwt extends Frame {
    awwt(String s){
        super(s);
    }
    public static void main(String[] args){
        awwt o1=new awwt("FRAME EXTENDS");
        o1.setSize(500,500);
        o1.setLocation(200,200);
        o1.setVisible(true);
        
        Label l1=new Label("This is a Label", Label.CENTER);
        Font f=new Font("Calibiri",Font.BOLD,20);
        l1.setFont(f);

        o1.add(l1);
    }
}
