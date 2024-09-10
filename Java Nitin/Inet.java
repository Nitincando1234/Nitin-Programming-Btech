import java.net.*;
public class Inet{
    public static void main(String[] args) throws UnknownHostException{
        InetAddress hp = InetAddress.getLocalHost();
        System.out.println("Local Host: " + hp);
        hp = InetAddress.getByName("google.com");
        System.out.println("Name of the server: " + hp);
        InetAddress[] all = InetAddress.getAllByName("www.nba.com");
        System.out.println("List items");
        for(InetAddress a : all)
            System.out.println(a);
    }
}