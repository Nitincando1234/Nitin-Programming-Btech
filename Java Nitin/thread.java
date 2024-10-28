import java.lang.Thread;
class MyThread extends Thread{
    public void run(){
        System.out.println("In Thread");
        for(int i=0;i<5;i++){
            System.out.println("Hi");
        }System.out.println("Exiting Thread !");
    }
}
public class thread {
    public static void main(String[] args){
        MyThread t=new MyThread();
        t.start();
        System.out.println("Exiting main Thread !");
    }
}
