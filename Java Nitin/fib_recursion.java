import java.util.Scanner;
class Main {
	static void fib(int len,int a,int b,int c){
	if(len>0){
	c=a+b;
	System.out.println(a);
	a=b;
	b=c;
	fib(len-1,a,b,c);	
		}	}
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the length of the series: ");
		int len=sc.nextInt();
		fib(len,0,1,0);
	}
}