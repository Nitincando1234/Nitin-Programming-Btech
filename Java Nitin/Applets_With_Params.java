import java.awt.Graphics;
import java.applet.*;
/*
<applet code = "Applets_With_Params.java" height = 512 width = 512>
<param name=fontName value=Courier>
<param name=fontSize value=14>
<param name=leading value=2>
<param name=accountActivated value=true>
</applet>
*/
public class Applets_With_Params extends Applets{
    String fontName;
    int fontSize, leading;
    boolean accountActivated;
    public void start(){
        String param;
        fontName = getParameter("fontName");
        if(fontName == null) fontName = "Not Found";
        param = getParameter("fontSize");
        try{
        if(param != null) fontSize = Integer.parseInt(param);
        else fontSize = 0;
        }
        catch (NumberFormatException e){
            fontSize = -1;
        }
        param = getParameter("leading");
        try{
            if(param != null) leading = Integer.parseInt(param);
            else leading = 0;
        }
        catch (NumberFormatException e){
            leading = -1;
        }
        param = getParameter("accountActivated");
        if(param != null)
            accountActivated = Boolean.valueOf(param).booleanValue();
    }
    public void paint(Graphics g){
        g.drawString("Font Name: " + fontName, 0, 20);
        g.drawString("Font Size: " + fontSize, 0, 40);
        g.drawString("Leading: " + leading, 0, 60);
        g.drawString("Account Activated Status: " + accountActivated, 0, 80);
    }
}
