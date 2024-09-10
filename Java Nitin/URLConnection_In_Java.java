import java.io.IOException;
import java.io.InputStream;
import java.net.*;
import java.util.Date;
public class URLConnection_In_Java {
    public static void main(String[] args) throws MalformedURLException, IOException {
        URL hp = new URL("https://www.apache.org");
        URLConnection hpCon = hp.openConnection();
        long d;
        d = hpCon.getDate();
        if(d == 0)
            System.out.println("No System Date Information !");
        System.out.println("Date: " + new Date(d));
        d = hpCon.getLastModified();
        if(d == 0)
            System.out.println("No Last Modified Information !");
        System.out.println("Last Modified: " + new Date(d));
        d = hpCon.getExpiration();
        if(d == 0)
            System.out.println("No Expiration Information !");
        System.out.println("Expiration Date: " + new Date(d));
        // get content length
        int len = hpCon.getContentLength();
        if(len == -1) System.out.println("Content is Unavailable !");
        else System.out.println("Content Length: " + len);
        System.out.println("=====================Content=====================");
        if(len != 0){
            int i = len, c;
            InputStream in = hpCon.getInputStream();
            while(((c = in.read()) != -1) && (--i > 0))
                System.out.print((char) c);
            in.close();
        }
        else System.out.println("Content is Unavailable !");
    }
}
