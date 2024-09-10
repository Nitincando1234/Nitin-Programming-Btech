import java.lang.Thread;
import java.lang.Runnable;
class Thread1 implements Runnable{
    Thread t1;
    public Thread1(String name){
        t1=new Thread(this,name);
        System.out.println("First Thread Initialized !");
        t1.start();    }
    public void run(){
        for(int i=1;i<=50000;i++){
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
        for(int i=50100;i<=100000;i++){
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
        for(int i=100100;i<=200000;i++){
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
        for(int i=100100;i<=200000;i++){
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
        for(int i=100100;i<=200000;i++){
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
        for(int i=100100;i<=200000;i++){
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
        for(int i=100100;i<=200000;i++){
            System.out.println("i "+i);
        }
    }
}
public class MultiThreadusingRunnable {
    public static void main(String[] args){
        System.out.println("Main Thread Started !");
        new Thread1("Thread1");
        new Thread2("Thread2");
        new Thread3("Thread3");
        new Thread4("Thread3");
        new Thread5("Thread3");
        new Thread6("Thread3");
        new Thread7("Thread3");
    }
}
