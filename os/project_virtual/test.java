package project_virtual;
import java.awt.*;
import java.awt.event.*;

public class test extends Frame implements ComponentListener {
    private Label label;

    public test() {
        setSize(300, 200);

        label = new Label("Click the button");
    //    / label.setAlignment(Label.CENTER);

        //setLayout(new BorderLayout());
        add(label);

        addComponentListener(this);

        setVisible(true);
        
    }

    public static void main(String[] args) {
        new  test();
    }

    @Override
    public void componentResized(ComponentEvent e) {
        label.setText("Component Resized: " + getSize().width + " x " + getSize().height);
    }

    @Override
    public void componentMoved(ComponentEvent e) {
        label.setText("Component Moved: " + getLocation().x + ", " + getLocation().y);
    }

    @Override
    public void componentShown(ComponentEvent e) {
        label.setText("Component Shown");
    }

    @Override
    public void componentHidden(ComponentEvent e) {
        label.setText("Component Hidden");
    }
}