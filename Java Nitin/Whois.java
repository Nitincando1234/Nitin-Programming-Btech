import java.io.*;
import java.net.*;

public class Whois {
    public static void main(String[] argString) throws IOException, UnknownHostException{
        int c;
        Socket s = new Socket("whois.verisign-grs.com", 43);
        InputStream in = s.getInputStream();
        OutputStream out = s.getOutputStream();
        String str = (argString.length == 0 ? "google.com" : argString[0]) + "\n";
        byte buf[] = str.getBytes();
        out.write(buf);
        while ((c = in.read()) != -1){
            System.out.print((char) c);
        }
        s.close();
    }
}
