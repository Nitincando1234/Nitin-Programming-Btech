import java.util.Scanner;
public class pattern4 {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the size of the pattern: ");
        int size=in.nextInt();
        if(size%2==0){
        size++;
        for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
        if(i==1||i==size||j==1||j==size||i==size/2+1||j==size/2+1)
        System.out.print("*");
        else
        System.out.print(" ");
        }System.out.println();
    }
    }
    else{
        for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            if(i==1||i==size||j==1||j==size||i==size/2+1||j==size/2+1)
            System.out.print("*");
            else
            System.out.print(" ");
        }
        System.out.println();
        }
    }
    }
}
