import java.lang.Thread;
import java.lang.Runnable;
class Thread1 implements Runnable{
    Thread t1;
    public Thread1(String name){
        t1=new Thread(this,name);
        System.out.println("First Thread Initialized !");
        t1.start();    }
    public void run(){
        for(int i=1;i<=500;i++){
            System.out.println("i "+i);
        }
    }
}
class Thread2 implements Runnable{
    Thread t2;
    public Thread2(String name){
        t2=new Thread(this,name);
        System.out.println("Second Thread Initialized !");
        t2.start();    }
    public void run(){
        for(int i=501;i<=1000;i++){
            System.out.println("i "+i);
        }
    }
}
class Thread3 implements Runnable{
    Thread t3;
    public Thread3(String name){
        t3=new Thread(this,name);
        System.out.println("Second Thread Initialized !");
        t3.start();    }
    public void run(){
        for(int i=1001;i<=2000;i++){
            System.out.println("i "+i);
        }
    }
}
class Thread4 implements Runnable{
    Thread t4;
    public Thread4(String name){
        t4=new Thread(this,name);
        System.out.println("Second Thread Initialized !");
        t4.start();    }
    public void run(){
        for(int i=1001;i<=2000;i++){
            System.out.println("i "+i);
        }
    }
}
class Thread5 implements Runnable{
    Thread t5;
    public Thread5(String name){
        t5=new Thread(this,name);
        System.out.println("Second Thread Initialized !");
        t5.start();    }
    public void run(){
        for(int i=1001;i<=2000;i++){
            System.out.println("i "+i);
        }
    }
}
class Thread6 implements Runnable{
    Thread t6;
    public Thread6(String name){
        t6=new Thread(this,name);
        System.out.println("Second Thread Initialized !");
        t6.start();    }
    public void run(){
        for(int i=1001;i<=2000;i++){
            System.out.println("i "+i);
        }
    }
}
class Thread7 implements Runnable{
    Thread t7;
    public Thread7(String name){
        t7=new Thread(this,name);
        System.out.println("Second Thread Initialized !");
        t7.start();    }
    public void run(){
        for(int i=1001;i<=2000;i++){
            System.out.println("i "+i);
        }
    }
}
public class joinandisalivethread {
    public static void main(String []args){
        Thread1 t1=new Thread1("Thread!");
        Thread2 t2=new Thread2("Thread!");
        Thread3 t3=new Thread3("Thread!");
        Thread4 t4=new Thread4("Thread!");
        Thread5 t5=new Thread5("Thread!");
        Thread6 t6=new Thread6("Thread!");
        Thread7 t7=new Thread7("Thread!");
        try{
            t1.t1.join();
            t2.t2.join();
            t3.t3.join();
            t4.t4.join();
            t5.t5.join();
            t6.t6.join();
            t7.t7.join();
        }
        catch(InterruptedException e){
            System.out.println("Interrupted !");
        }
        System.out.println("Thread 1 is alive: "+(t1.t1.isAlive()));
        System.out.println("Thread 2 is alive: "+(t2.t2.isAlive()));
        System.out.println("Thread 3 is alive: "+(t3.t3.isAlive()));
        System.out.println("Thread 4 is alive: "+(t4.t4.isAlive()));
        System.out.println("Thread 5 is alive: "+(t5.t5.isAlive()));
        System.out.println("Thread 6 is alive: "+(t6.t6.isAlive()));
        System.out.println("Thread 7 is alive: "+(t7.t7.isAlive()));}
        
    }

