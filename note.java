// Application和applet的区别
// 
// Applet没有main函数

// 判断闰年 
import java.util.Scanner;
public class LeapYear {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    System.out.println("请输入一个年份：");
    long year = scan.nextLong();
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
      System.out.println(year + "年是闰年！");
    } else {
      System.out.println(year + "年是平年！");
    }
  }
}

// 正方形，长方形类

// 圆类
public class Cricle {
  static double PI = 3.14;
  int radius;
  // 计算周长
  public double circumference() {
    return 2*PI*radius;
  }
  // 计算面积
  public double area() {
    return PI*radius*radius;
  }
}

// 矩形类
public class Rectangle {
  double width;
  double height;
  public double area() {
    return width*height;
  }
}

public class AreaTester {
  public static void main (String args[]) {
    Cricle c = new Cricle();
    c.radius = 50;
    System.out.println(c.area());
  }
}

// 99乘法表
public class MultiplicationTable {
    public static void main(String[] args) {
        for(int i=1;i<=9;i++) {
            for(int j=1;j<=i;j++) {
                System.out.print(j+"×"+i+"="+i*j+"\t");// \t 跳到下一个TAB位置
            }
            System.out.println();
        }
    }
}
