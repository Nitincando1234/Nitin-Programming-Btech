class Customer{
    int amount = 10000;
    synchronized public void withdraw(int amount){
        System.out.println("Withdrawing ...");
        if(this.amount < amount){
            System.out.println("Amount is less, Waiting for deposit ...");
            try{
                wait();
            }
            catch (InterruptedException e){
                System.err.println("Interrupted !!!");
            }
        }
        else{
            this.amount -= amount;
        }
        System.out.println("Withdraw Complete !!!");
    }
    synchronized public void deposit(int amount){
        System.out.println("Going to deposite" + amount);
        this.amount += amount;
        System.out.println("Deposit Complete !!!");
        notify();
    }
}
public class InterThreadCommunication {
    public static void main(String [] argString){
        Customer c = new Customer();
        new Thread(){
            public void run(){
                c.withdraw(20000);
            }
        }.start();
        new Thread(){
            public void run(){
                c.deposit(20000);
            }
        }.start();
        System.out.println("Main Thread Exiting ...");
    }
}
