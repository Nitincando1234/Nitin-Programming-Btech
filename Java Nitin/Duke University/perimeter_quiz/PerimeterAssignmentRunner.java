import edu.duke.*;
import java.io.File;

public class PerimeterAssignmentRunner {
    public double mysteryShape(Shape s) {
    double tmp = 0;
     // Use the library's method to get the number of points
    for (Point p : s.getPoints()) {
        if (p.getX() > 0 ) {
            if(p.getY()<0){
            tmp = tmp + 1;}
        }
    }
    return tmp / getNumPoints(s);
}

    public double getPerimeter (Shape s) {
        // Start with totalPerim = 0
        double totalPerim = 0.0;
        // Start wth prevPt = the last point 
        Point prevPt = s.getLastPoint();
        // For each point currPt in the shape,
        for (Point currPt : s.getPoints()) {
            // Find distance from prevPt point to currPt 
            double currDist = prevPt.distance(currPt);
            // Update totalPerim by currDist
            totalPerim = totalPerim + currDist;
            // Update prevPt to be currPt
            prevPt = currPt;
        }
        // totalPerim is the answer
        return totalPerim;
    }

    public int getNumPoints (Shape s) {
        // Put code here
        int numShape =0;
        for(Point countPoint: s.getPoints()){
        numShape++;}
        return numShape;
    }

    public double getAverageLength(Shape s) {
        // Put code here
        int countNums= getNumPoints(s);
        double perimlength= getPerimeter (s);
        double avg= perimlength/((double)countNums);
        return avg;
    }

    public double getLargestSide(Shape s) {
        // Put code here
        double longestSide=0.0;
        double currDist=0.0;
        Point prevPoint= s.getLastPoint();
        for(Point currPoint : s.getPoints())   
        {
        if((currDist=(currDist=prevPoint.distance(currPoint)))>longestSide){longestSide=currDist;}}
        return longestSide;
    }

    public double getLargestX(Shape s) {
        // Put code here
        double largestX=0.0;
       
        for( Point currPoint: s.getPoints() ){
            double x=currPoint.getX();
           if(x>largestX){
            largestX=x;}
        }
        return largestX;
    }

    public double getLargestPerimeterMultipleFiles() {
        // Put code here
        double largePerim=0;
        
        DirectoryResource directory= new DirectoryResource();
        for(File f:directory.selectedFiles()){
        
        FileResource fr= new FileResource(f);
        Shape s= new Shape(fr);
        double length=getPerimeter(s);
        if(length>largePerim){
        largePerim=length;
        
        }
        }
        
        return largePerim;
    }

    public String getFileWithLargestPerimeter() {
        // Put code here
        File temp = null; // replace this code
        double largePerim=0;
        DirectoryResource directory= new DirectoryResource();
        for(File f:directory.selectedFiles()){
        FileResource fr= new FileResource(f);
             Shape s= new Shape(fr);
        double length=getPerimeter(s);
        if(length>largePerim){
        temp=f;
        }
        }
        
        return temp.getName();
    }

    public void testPerimeter () {
        FileResource fr = new FileResource();
        Shape s = new Shape(fr);
        double length = getPerimeter(s);
        int countNums= getNumPoints(s);
        double avgLenght= getAverageLength(s);
        double longestSide = getLargestSide(s);
        double largestX =getLargestX(s);
        String name= new String();
        name = getFileWithLargestPerimeter();
        double largestPerim=getLargestPerimeterMultipleFiles();
       
        System.out.println("Length of Longest Side =" +longestSide);
        System.out.println("Largest X component="+largestX);
        System.out.println("Number in Shape =" +countNums);
       System.out.println("Average of Lengths ="+ avgLenght);
        System.out.println("perimeter = " + length);
       System.out.println("Largset Perimeter among the shapes from Selected Files="+ largestPerim);
       
        System.out.println("File name with largset Perimeter= "+ name);
        /* double mystery=mysteryShape(s);
       System.out.println("Mystery:"+mystery);*/
    }
    
    public void testPerimeterMultipleFiles() {
        // Put code here
        double perimeter= getLargestPerimeterMultipleFiles();
        System.out.println("Largest Perimeter ="+perimeter);
    }

    public void testFileWithLargestPerimeter() {
        // Put code here
        String name= new String();
        name=getFileWithLargestPerimeter();
        System.out.println("File with largest perimeter ="+name);
    }

    // This method creates a triangle that you can use to test your other methods
    public void triangle(){
        Shape triangle = new Shape();
        triangle.addPoint(new Point(0,0));
        triangle.addPoint(new Point(6,0));
        triangle.addPoint(new Point(3,6));
        for (Point p : triangle.getPoints()){
            System.out.println(p);
        }
        double peri = getPerimeter(triangle);
        System.out.println("perimeter = "+peri);
    }

    // This method prints names of all files in a chosen folder that you can use to test your other methods
    public void printFileNames() {
        DirectoryResource dr = new DirectoryResource();
        for (File f : dr.selectedFiles()) {
            System.out.println(f);
        }
    }

    public static void main (String[] args) {
        PerimeterAssignmentRunner pr = new PerimeterAssignmentRunner();
        pr.testPerimeter();
        //pr.testFileWithLargestPerimeter();
        //pr.testPerimeterMultipleFiles();
    }
}
