// Applet程序
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
public class SwingApplet extends JApplet {
  public void init() {
    // 重写init
    Container contentPane = getContentPane();
    // 内容面板  
      contentPane.setLayout(new GridLayout(2, 1));
      JButton button = new JButton("Click me");
      final JLable lable = new JLable();
      contentPane.add(button);
      contentPane.add(lable);
      button.addActionListener(
          // 创建事件监听器，对click做出反应
          new ActionListener() {
          public void actionPerformed(ActionEvent event) {
            String information = JOptionPane.showInputDialog("请输入一串字符");
            lable.setText(information);
          }
          });
  }
}

// Application程序
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
public class SwingApplication {
  public static void main(String[] args) {
    JFrame f = new JFrame("Simple Swing Application");
    Container contentPane = f.getContentPane();
    // 内容面板  
      contentPane.setLayout(new GridLayout(2, 1));
      JButton button = new JButton("Click me");
      final JLable lable = new JLable();
      contentPane.add(button);
      contentPane.add(lable);
      button.addActionListener(
          // 创建事件监听器，对click做出反应
          new ActionListener() {
          public void actionPerformed(ActionEvent event) {
            String information = JOptionPane.showInputDialog("请输入一串字符");
            lable.setText(information);
          }
          });
          f.setSize(200, 100);
          f.setVisible(true);
          f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  }
}
