class Callme{
    synchronized void call(String msg) throws  InterruptedException{
        System.out.print("[" + msg);
        try{
            Thread.sleep(1000);
        }catch (InterruptedException e){
            System.err.println("Interrupted !!!");
        }
        System.out.println("]");
    }
}
class Caller implements Runnable{
    String message;
    Callme target;
    Thread t;
    Caller(Callme targ, String s){
     t = new Thread(this);
     target = targ;
     message = s;
     t.start();
    }
    public void run(){
        try{
        target.call(message);}
        catch (InterruptedException e){
        }
    }
}
public class Synchronized_Methods {
    public static void main(String []argString){
        Callme call = new Callme();
        Caller ob1 = new Caller(call, "Hello");
        Caller ob2 = new Caller(call, "Synchronized");
        Caller ob3 = new Caller(call, "World");
        ob1.t.setPriority(5);
        ob2.t.setPriority(10);
        ob3.t.setPriority(5);
        try{
            ob1.t.join();
        }
        catch (InterruptedException e){
            System.err.println("Interrupted !!!");
        }
        try{
            ob2.t.join();
        }
        catch (InterruptedException e){
            System.err.println("Interrupted !!!");
        }
        try{
            ob3.t.join();
        }
        catch (InterruptedException e){
            System.err.println("Interrupted !!!");
        }
        System.out.println("Main Thread Exiting ...");
    }
}
