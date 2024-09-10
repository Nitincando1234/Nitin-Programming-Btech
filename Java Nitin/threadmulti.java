import java.lang.Thread;
class MyThread extends Thread{
    public void run(){
        System.out.println("In Thread");
        int i=1;
        for(i=1;i<=500;i++){
            System.out.println("i: "+i);
    }try{
    if(i==500){
    this.stop();}}
    finally{
        System.out.println("Exiting First Thread!");
    }
}}
class MyThread1 extends Thread{
    public void run(){
        System.out.println("In Thread");
        int i=1;
        for(i=500;i<=1000;i++){
            System.out.println("i: "+i);
    }
    if(i==500)
    this.stop();
}}
public class threadmulti {
    public static void main(String[] args){
    MyThread m1=new MyThread();
    MyThread1 m2=new MyThread1();
    m1.start();
    m2.start();
    System.out.println("Exited Main Thread !");
}
}
