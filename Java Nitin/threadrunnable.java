import java.lang.Runnable;
class MyThread1 implements Runnable{
    public void run(){
        for(int i=0;i<10000;i++){
            System.out.println("i\n"+i);
        }
    }
}
public class threadrunnable{
    public static void main(String []args){
        MyThread1 m=new MyThread1();
        Thread t=new Thread(m);
        System.out.println("Main Thread");
        t.start();
    }
}
