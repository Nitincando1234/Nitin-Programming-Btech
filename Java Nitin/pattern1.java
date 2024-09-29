//     *
//    ***
//   *****
//  *******
// *********
import java.util.Scanner;
class pattern1{
    public static void main(String []args){
    Scanner in =new Scanner(System.in);   
    int size;
    System.out.print("Enter the size of the Pattern: ");
    size=in.nextInt();
    for(int i=1;i<=size;i++){
    for(int j=i;j<=size;j++)
    System.out.print(" ");
    for(int k=1;k<i;k++)
    System.out.print("*");
    for(int j=1;j<=i;j++){
    System.out.print("*");
    }
    System.out.println();
    }
    }
}