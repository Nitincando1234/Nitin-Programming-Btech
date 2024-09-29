import java.util.Scanner;
public class pattern2 {
    public static void main(String []args){
        Scanner in=new Scanner(System.in);
        int size;
        System.out.print("Enter the size of the Pattern: ");
        size=in.nextInt();
        for(int i=1;i<size;i++){
        for(int j=1;j<=i;j++)
        System.out.print("*");
        System.out.println();
        }for(int i=1;i<=size;i++){
            for(int j=i;j<=size;j++)
            System.out.print("*");
            System.out.println();
            }
    }
}
