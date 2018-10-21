import java.util.Scanner; 
public class LeapYear {
  public static void main(String [] args) {
    Scanner sean = new Scanner(System.in); 
    long year = sean.getLong();
    if ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
      System.out.println("闰年");
    } else {
      System.out.println("平年");
    }
  }
}

public class Cricle {
  static double PI = 3.14;
  int radius;
  public double area() {
    return PI*radius*radius;
  }
}

public class test {
  public static void main(String[] args) {
    Cricle c = new Cricle();
    c.radius = 50;
    System.out.println(c.area());
  }
}

// Applet
// 我给你分享 你都不愿意听 
// 我自己又不看‘
import java.awt.*
import java.awt.event.*;
import javax.swing.*;
public class SwingApplet extends JApplet {
  public void init() {
    Container contentPane = getContentPane();
      // 内容模板
      contentPane.setLayout(new GridLayout(2,1));
      JButton button = new JButton("click me");
      final JLable lable = new JLable();
      contentPane.add(button);
      contentPane.add(lable);
      // 实现button功能
      button.addActionLister(
          new ActionListener() {
            public void actionPerformed(ActionEvent event) {
              string information = JOptionPane.showInputDialog("请输入一串字符");
              lable.setText(information);
            }
          });
  }
}

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class SwingApplication {
  public static void main(String[] args) {
    JFrame f = new JFrame("Simple Swing");
    Container contentPane = f.getContentPane();
    JButton button = new JButton("Click me");
    final JLable lable = new JLable();
    contentPane.add(button);
    contentPane.add(lable);
    button.addActionLister(
        new ActionListener() {
          public void actionPerformed(ActionEvent event) {
            string information = JOptionPane.showInputDialog("请输入一串字符");
            lable.setText(information);
          }
        });
    f.setSize(200, 100);
    f.setVisible(true);

  }
}




