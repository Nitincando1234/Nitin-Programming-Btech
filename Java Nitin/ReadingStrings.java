import java.io.*;
public class ReadingStrings {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter \'quit\' to stop !!!");
        String inputString;
        do {
            inputString = br.readLine();
            System.out.println(inputString);
        } while ( ! inputString.equals("quit"));
    }
}
