import java.net.*;
public class URLjava {
    public static void main(String[] argString) throws MalformedURLException{
        URL hp = new URL("https://www.google.com");
        System.out.println("PROTOCOL: " + hp.getProtocol());
        System.out.println("PORT: " + hp.getPort());
        System.out.println("HOST: " + hp.getHost());
        System.out.println("FILE: " + hp.getFile());
        System.out.println("EXTERNAL LINK: " + hp.toExternalForm());
    }
}
