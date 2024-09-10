import java.io.PrintWriter;

public class WritingConsoleOutput {
    public static void main(String[] args){
        int a = 'A';
        System.out.flush();
        System.out.write(a);        // Byte Stream writer
        // ?? where is output of write() -> flush the output to screen
        System.out.flush();
        // Using PrintWriter class
        PrintWriter pr = new PrintWriter(System.out, false);
        // Character stream "pr" writes ASCII value of the A
        pr.println("\n" + a);
        // Flushes the output
        pr.flush();
    }
}
