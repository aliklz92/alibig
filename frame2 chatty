package chatty;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class frame2  extends JFrame{

    frame1 frameA;
    frame3 frameC;

    JFrame frame2=new JFrame("Ali");
    JPanel panel = new JPanel();
    JTextField tf = new JTextField(10);
    JTextArea jArea=new JTextArea();
    JButton b=new JButton("Send");


    public void setFrameA(frame1 frameA){
        this.frameA=frameA;
    }

    public void setFrameC(frame3 frameC) {
        this.frameC = frameC;
    }

    public void Send(String text) {

        String s=jArea.getText();
        s=s+"\n"+"Ali: "+text ;

        frameA.jArea.setText(s);
        frameC.jArea.setText(s);

        jArea.setText(s);

        };



    public void  frame_2()
    {
            jArea.setEditable(false);
            frame2.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame2.setSize(300, 500);

            tf.setBounds(50, 100, 150, 20);
            jArea.setBounds(10,30, 200,200);

            frame2.add(jArea);
            panel.add(tf);
            panel.add(b);
              b.addActionListener(new ActionListener() {
                public void actionPerformed(ActionEvent e){
                Send(tf.getText());
                tf.setText("");

            }
        });
              frame2.getContentPane().add(BorderLayout.SOUTH, panel);
              frame2.getContentPane().add(BorderLayout.NORTH, tf);
              frame2.setVisible(true);
              Font font = new Font("Arial", Font.ROMAN_BASELINE, 15);
              jArea.setFont(font);
              jArea.setForeground(Color.DARK_GRAY);

    }




}
