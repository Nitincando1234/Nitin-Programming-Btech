import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String inputString, encryptedString;
        System.out.print("Which mode:\n1. AES\n2. RSA\n3. MD5: ");
        int choice = sc.nextInt();
        System.out.print("Enter the String to be encrypted: ");
        inputString = sc.next();
        System.out.println("Original String: " + inputString);
        if (choice == 1) {
            AES aes = new AES();
            encryptedString = aes.encryptText(inputString);
            System.out.println("Encrypted String: " + encryptedString);
            System.out.println("Decrypted String: " + aes.decryptText(encryptedString));
        }
        else if (choice == 2) {
            RSA rsa = new RSA();
            encryptedString = rsa.encryptText(inputString);
            System.out.println("Encrypted String: " + encryptedString);
            System.out.println("Decrypted String: " + rsa.decryptText(encryptedString));
        }
        else if (choice == 3) {}

        sc.close();
    }

}
