import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/*
 * Despite what the text says, this is not a real virus, all it does is
 * create new windows of itself when the user tries to close the first
 * window, but it is a good program to annoy your friends. This time, they don't
 * have to do the closing
 * */

public class AdvancedHydra {
    private JFrame mainFrame;
    private JLabel warning;

    public void makeWindow(){
        this.mainFrame = new JFrame("Hydra Virus 1.0.0");
        this.warning = new JLabel("", JLabel.CENTER);

        this.warning.setText("This is the Hydra Virus, cut one head off, two more grow.");
        this.mainFrame.add(warning);

        this.mainFrame.setSize(500, 100);

        this.mainFrame.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent we){
                makeWindow();
                makeWindow();
            }
        });

        this.mainFrame.setVisible(true);
        mainFrame.setLocation((int)(Math.random() * 1920), (int)(Math.random() * 1080));

        mainFrame.dispatchEvent(new WindowEvent(mainFrame, WindowEvent.WINDOW_CLOSING));
    }

    public AdvancedHydra() {
        this.makeWindow();
    }

    public static void main(String args[]){
        Hydra first = new Hydra();

    }
}
