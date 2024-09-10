import java.io.*;

public class FileHandling1 {
    public static void main(String[] args) throws IOException{
        FileInputStream in = null;
        FileOutputStream out = null;
        int c;
        try{
        in = new FileInputStream("input.txt");
        out = new FileOutputStream("output.txt");
        while((c = in.read())!=-1)
            out.write(c);
        }
        finally{
        if(in != null)
        in.close();
        if(out != null)
        out.close();
        }
        System.out.print("File Copied Successfully !");
    }
}
