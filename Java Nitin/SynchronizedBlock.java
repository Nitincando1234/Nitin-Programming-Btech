class Called{
    void call(String msg){
        System.out.println("[" + msg);
        try{
            Thread.sleep(1000);
        }
        catch (InterruptedException e){
            System.out.println("Interrupted !!!");
        }
        System.out.println("]");
    }
}
class Callee implements Runnable{
    String message;
    Called target;
    Thread t;
    Callee(Called targ, String s){
        target = targ;
        message = s;
         Thread t= new Thread(this);
    }
    public void run(){
        synchronized (target){
            target.call(message);
        }
    }
}
public class SynchronizedBlock {
    public static void main(String[] argString){
        Called called = new Called();
        Callee ob1 = new Callee(called, "Hello");
        Callee ob2 = new Callee(called, "Synchronized");
        Callee ob3 = new Callee(called, "World");
        try{
            ob1.t.join();
            ob2.t.join();
            ob3.t.join();
        }
        catch (InterruptedException e){
            System.err.println("Interrupted !!!");
        }
        System.out.println("Main Thread Exiting ...");
    }
}
