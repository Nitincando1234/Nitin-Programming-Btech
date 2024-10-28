interface Payable{
    public double getPaymentAmount();
}
class Invoice implements Payable{
    private int quantity;
    private double price;
    private String name;
    public Invoice(String n, double p, int count){
        name=n;
        price=p;
        quantity=count;
    }
    @Override
    public double getPaymentAmount(){
        return quantity*price;
    }
    @Override
    public String toString(){
        return String.format("Invoice\nName: %s\nPrice: %.2f\nQuantity: %d",name,price,quantity);
    }
}
class Staff implements Payable{
    private double salary;
    private String name;
    public Staff(String n, double s){
        name=n;
        salary=s;
    }
    @Override
    public double getPaymentAmount(){
        return salary;
    }
    @Override
    public String toString(){
        return String.format("\nStaff Salary:\nName: %s\nSalary: %.2f\n",name,salary);
    }

}
public class MyInter {
    public static void main(String [] args){
        Payable []payable=new Payable[2] ;
        payable[0]=new Invoice("Ball",300.50,4);
        payable[1]=new Staff("Nitin Sharma",100000);
        for(Payable pbl: payable){
            System.out.printf("%s\tPayment Due: %.2f",pbl.toString(),pbl.getPaymentAmount());
        }
    }
}
