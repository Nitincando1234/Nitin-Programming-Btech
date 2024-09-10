import java.applet.Applet;
import java.awt.Graphics;

/* <applet code="MyApplet.class" width="500" height="400">
   </applet>
*/

public class MyApplet extends Applet {
    public void init() {
        System.out.println("Applet has Initialized !");
    }

    public void start() {
        System.out.println("Applet has Started !");
    }

    public void paint(Graphics g) {
        g.drawString("Welcome", 10, 50);
    }

    public void stop() {
        System.out.println("Applet has Stopped !");
    }

    public void destroy() {
        System.out.println("Applet has been Destroyed !");
    }
}
