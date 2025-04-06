import java.security.MessageDigest;
import java.util.Scanner;

public class MD5 {
    
    public static String hash(String inputData) {
        try {
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] digest = md.digest(inputData.getBytes());
            StringBuilder hashHex = new StringBuilder();
            for (byte b: digest) {
                hashHex.append(String.format("%02x-", b));
            }
            hashHex.setCharAt(hashHex.length() - 1, ' ');
            return hashHex.toString();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }

    public static void main(String[] args) {
        String inputString;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the String to be hashed: ");
        inputString = in.next();
        System.out.println("Hashed String: " + hash(inputString));
        in.close();
    }
}

