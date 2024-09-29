import java.util.Scanner;
public class tilingproble {
    static int problemTiling(int n){
    if(n<=0)return 0;
    if(n==1)return 1;
    if(n==2)return 1;
    if(n==3)return 2;
    return problemTiling(n-1)+problemTiling(n-2);
    }
    public static void main(String []args){
    Scanner in=new Scanner(System.in);
    System.out.print("Enter the length of the floor: ");
    int n=in.nextInt();
    if(n<0){
    System.out.println("Wrong length of the floor !");
    return;
    }
    System.out.println("No. of ways to tile the floor: "+problemTiling(n));
    }
}
