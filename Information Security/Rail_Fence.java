import java.util.Scanner;

public class Rail_Fence{
    public static void encryptString(String inputData, int key) {
        inputData = inputData.replace(".\\s", "");  // whitespace -> ""
        char[][] rail = new char[key][inputData.length()];
        String rail_string = "";
        int row = 0, check = 0; // check == 0 -> up
        for (int i = 0; i < key; i++) {
            for (int j = 0; j < inputData.length(); j++) rail[i][j] = '.';
         }
        for (int i = 0; i < inputData.length(); i++) {
            if (check == 0) {
                rail[row++][i] = inputData.charAt(i);
                if (row == key) {
                    check = 1;
                    row--;
                }
            }
            else if (check == 1) 
                rail[--row][i] = inputData.charAt(i); 
                if (row == 0) {
                    check = 0;
                    row = 1;
                }
        }
        for (int i = 0; i < key; i++) {
            for (int j = 0; j < inputData.length(); j++) {
                rail_string += rail[i][j];
            }
        }
        System.out.println("Encrypted String: " + rail_string.replace(".", ""));
    }
    public static void decryptString(String inputData, int key) {
        inputData = inputData.replace(".\\s", "");  // whitespace -> ""
        char[][] rail = new char[key][inputData.length()];
        String decrypted_rail_string = "";
        int row = 0, check = 0; // check == 0 -> up
        for (int i = 0; i < key; i++) {
            for (int j = 0; j < inputData.length(); j++) rail[i][j] = '.';
         }
        for (int i = 0; i < inputData.length(); i++) {
            if (check == 0) {
                rail[row++][i] = inputData.charAt(i);
                if (row == key) {
                    check = 1;
                    row--;
                }
            }
            else if (check == 1) 
                rail[--row][i] = inputData.charAt(i); 
                if (row == 0) {
                    check = 0;
                    row = 1;
                }
        }
        int order = 0;
        // get the reorder
        for (int i = 0; i < key; i++) {
            for (int j = 0; j < inputData.length(); j++) {
                String c = rail[i][j] + "";
                if (c.matches("\\.")) continue;
                else {
                    rail[i][j] = inputData.charAt(order++);
                }
            }
        }
        row = check = 0;
        for (int i = 0; i < inputData.length(); i++) {
            if (check == 0) {
                decrypted_rail_string += rail[row++][i] + "";
                if (row == key) {
                    check = 1;
                    row--;
                }
            }
            else if (check == 1) 
                decrypted_rail_string += rail[--row][i] + "";
                if (row == 0) {
                    check = 0;
                    row = 1;
                }
        }
        System.out.println("The decrypted string: " + decrypted_rail_string);
    }
    public static void main(String[] args) {
        String str; int key;
        System.out.print("1. Encryption\n2. Decryption\n Your Choice (1, 2): ");
        Scanner sc = new Scanner(System.in);
        int choice = sc.nextInt();
        System.out.print("Enter the key: ");
        key = sc.nextInt();
        if (choice == 1) {
            System.out.print("Enter the String to be Encrypted: ");
            str = sc.next();
            encryptString(str, key);
        } else if (choice == 2) {
            System.out.print("Enter the encrypted string that to be decrypted: ");
            str = sc.next();
            decryptString(str, key);
        }
        sc.close();
    }
}