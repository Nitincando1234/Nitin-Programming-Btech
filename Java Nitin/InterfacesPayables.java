interface Payable{
	double getPaymentAmount();
}
class Items implements Payable{
	private double pricePerItem;
	private int quantity;
	private String name;
	Items(){
	pricePerItem = 0.0;
	quantity = 0;
	name = null;
	}
	Items(double pricePerItem, int quantity, String name){
	this.pricePerItem = pricePerItem;
	this.quantity = quantity;
	this.name = name;
	}
	@Override
	public double getPaymentAmount(){
	return (pricePerItem * quantity);
	}
	public String toString(){
	return String.format("Name of the Product: %s\nPrice per item: %.2f\nQuantity ordered: %d", name, pricePerItem, quantity);
	}
}
public class InterfacesPayables{
public static void main(String[] args){
	Payable[] payable = new Payable[1];
	payable[0] = new Items(40.0, 2, "Colgate");
	System.out.println("Total Price: " + payable[0].getPaymentAmount());
	System.out.println(payable[0].toString());
	
}
}
