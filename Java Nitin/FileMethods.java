import java.io.*;
public class FileMethods {
    public static void main(String [] arStrings) throws IOException{
        String fname = arStrings[0];
        File f = new File(fname);
        System.out.println("File Name: "+f.getName());
        System.out.println("File Path: "+f.getPath());
        System.out.println("File Absolute Path: "+f.getAbsolutePath());
        System.out.println("File Exists: "+f.exists());
        System.out.println("Parent File: "+f.getParent());
        if (f.exists()){
            System.out.println("Exists: "+f.exists());
            System.out.println("Is writeable: "+f.canWrite());
            System.out.println("Is readable: "+f.canRead());
            System.out.println("Is Directory: "+f.isDirectory());
            System.out.println("File size in bytes: "+f.length());
        }
    }
}
