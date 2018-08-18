/*
* Simple program that displays a clock
* */

import javax.swing.*;
import java.awt.*;
import java.util.Date;
import java.util.Calendar;

public class Clock implements Runnable{
    private JFrame mainFrame;
    private JLabel clockLabel;
    private final Dimension SCREEN_DIM = Toolkit.getDefaultToolkit().getScreenSize();

    public Clock() {
        // setting up the main frame
        mainFrame = new JFrame("Clock");
        mainFrame.setSize(SCREEN_DIM);
        mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        mainFrame.setLocationRelativeTo(null);
        mainFrame.setLayout(new FlowLayout());

        // creating the clock lable
        Date d = Calendar.getInstance().getTime();
        clockLabel = new JLabel();
        clockLabel.setText(d.getHours() + ":" + d.getMinutes() + ":" + d.getSeconds());
        clockLabel.setFont(new Font("arial", Font.BOLD, 72));
        mainFrame.add(clockLabel);

        mainFrame.setVisible(true);

        mainFrame.repaint();
    }



    public void update(){
        Date cd = Calendar.getInstance().getTime();
        this.clockLabel.setText(cd.getHours() + ":" + cd.getMinutes() + ":" + cd.getSeconds());
    }

    @Override
    public void run(){
        try {
            while (true){
                update();
                Thread.sleep(1000);
            }
        }catch (InterruptedException ie){
            ie.printStackTrace();
        }
    }

    public static void main(String[] args) {
         Clock c = new Clock();
         c.run();
    }
}
