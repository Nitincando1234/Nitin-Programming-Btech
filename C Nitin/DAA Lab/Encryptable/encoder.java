import java.util.Scanner;

public class encoder {
    public static void main(String[] args) {
        String str;
        System.out.print("Enter the string to encode: ");
        Scanner in = new Scanner(System.in);
        str = in.nextLine();
        System.out.println(str.getBytes().toString());
        in.close();
    }
}
