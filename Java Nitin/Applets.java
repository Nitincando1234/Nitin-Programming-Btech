import java.awt.*;
import java.applet.*;
/*
    <applet code = "Applets.class" width = 300 height = 100>
    Your Browser not Supports Applets
    </applet>
 */
public class Applets extends Applet{
    public void paint(Graphics g){
        g.drawString("Hello World", 20, 20);
    }
}
