import java.util.Scanner;
import java.util.InputMismatchException;
class InputMismatchDivision{
	public static int quotient(int numerator, int denominator){
	return (numerator / denominator);
	}
	public static void main(String[] args) throws InputMismatchException{
	Scanner inputObject = new Scanner(System.in);
	try{
	System.out.println("=============My=Division=Program==============");
	System.out.print("Enter the Numerator: ");
	int numerator = inputObject.nextInt();
	System.out.print("Ente the Denominator: ");
	int denominator = inputObject.nextInt();
	int divisionQuotient = quotient(numerator, denominator);
	System.out.println("Result of \nDivision of the " + numerator + " and " + denominator + " is " + divisionQuotient);
	}
	catch(InputMismatchException exceptionInstance){
	System.err.println("Input MisMatch Exception Occured !");
	exceptionInstance.printStackTrace();
	inputObject.nextLine();		// To flush the mismatched input
	System.err.println("Input Only Integers !!!");
	}
	}
}
