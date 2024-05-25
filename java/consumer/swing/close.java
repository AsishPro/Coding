import java.awt.*;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

class textfr extends Frame {
    public static void main(String[] Args){
      new textfr();
    }
    textfr(){
        addWindowListener(new WindowListener() {
            public void windowClosing(WindowEvent e){
                System.exit(0);

            }
            public void windowActivated(WindowEvent e){
                System.out.println("fuk");
            }
            public void windowClosed(WindowEvent e){}
            public void windowDeactivated(WindowEvent e){}
            public void windowDeiconified(WindowEvent e){}
            public void windowIconified(WindowEvent e){}
            public void windowOpened(WindowEvent e){}
        });
        setSize(500,500);
        setVisible(true);
    }
}