abstract class Shape{
	private double area;
	abstract public void getArea();
}
class Rectangle extends Shape{
	private double length, breadth;
	Rectangle(){
	length = breadth = 0;
	}
	Rectangle(double length, double breadth){
	this.length = length;
	this.breadth = breadth;
	}
	@Override
	public void getArea(){
	System.out.println("Area of Rectangle: " + (length * breadth));
	}
}
class Triangle extends Shape{
	private double height, base;
	Triangle(){
	height = base = 0;
	}
	Triangle(double height, double base){
	this.height = height;
	this.base = base;
	}
	@Override
	public void getArea(){
	System.out.println("Area of Triangle: " + (height * base) / 2);
	}

}
public class Shapes{
public static void main(String[] args){
	Rectangle newRectangle = new Rectangle(5.0, 2.0);
	newRectangle.getArea();
	Triangle newTriangle = new Triangle(10.0, 2.0);
	// Reference Types
	Shape[] s = new Shape[2];
	// Dynamic Method Dispatch
	s[0] = newRectangle;
	s[1] = newTriangle;
	for(Shape shape: s){
	if (shape instanceof Rectangle) System.out.println("Object of Type \"Rectangle\" Contained in Instance \"Shape\".");
	else if (shape instanceof Triangle) System.out.println("Object of Type \"Triangle\" Contained in Instance \"Shape\"."); 
	else System.out.println("Unknown Object !");
	}
}
}
