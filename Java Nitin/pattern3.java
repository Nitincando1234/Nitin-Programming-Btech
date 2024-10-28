import java.util.Scanner;
public class pattern3 {
    public static void main(String []args){
    Scanner in =new Scanner(System.in);
    System.out.print("Enter the size of the pattern: ");
    int size=in.nextInt();
    for(int i=1;i<size;i++){
        for(int j=1;j<=i;j++)
        System.out.print("*");
        for(int j=i;j<size;j++)
        System.out.print(" ");
        for(int j=i;j<size;j++)
        System.out.print(" ");
        for(int k=1;k<=i;k++)
        System.out.print("*");
        System.out.println();
    }
    for(int i=1;i<=size;i++){
        for(int j=i;j<=size;j++)
        System.out.print("*");
        for(int j=1;j<i;j++)
        System.out.print(" ");
        for(int k=1;k<i;k++)
        System.out.print(" ");
        for(int k=i;k<=size;k++)
        System.out.print("*");
        System.out.println();
    }
    }
}
