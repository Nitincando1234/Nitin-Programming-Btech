import java.util.Scanner;

class InvalidAgeException extends Exception{
	InvalidAgeException(String exception_String){
	super(exception_String);
	}
}
public class AgeCheckException{
public static void main(String[] argString){
	Scanner inputObject = new Scanner(System.in);
	try{
	System.out.printf("Enter Your Age: ");
	int age = inputObject.nextInt();

	if(age >= 18) System.out.println("You are eligible to vote !!!");
	else throw new InvalidAgeException("Minor User Exception !!!");
	}
	catch(InvalidAgeException age_Exception){
	System.out.println("You Are a Minor and hence can't vote !!!");
	}
}
}
