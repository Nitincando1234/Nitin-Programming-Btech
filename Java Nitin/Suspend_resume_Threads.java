class NewThread implements Runnable{
    Thread t;
    boolean suspendFlag;
    NewThread(String tName){
        t = new Thread(this, tName);
        suspendFlag = false;
        System.out.println(t + " has started !!!");
        t.start();
    }
    public void run(){

        try {
            for (int i = 15; i > 0; i--){
                System.out.print(t + ":" + i + "\n");
                System.out.flush();
                Thread.sleep(1000);
                synchronized (this){
                    while (suspendFlag){
                        wait();
                    }
                }
            }
        }catch (InterruptedException e){
            System.err.println("Interrupted !!!");
        }
    }
    public void mySuspend(){
        suspendFlag = true;
    }
    synchronized public void myResume(){
        suspendFlag = false;
        notify();
    }
}
public class Suspend_resume_Threads {
    public static void main(String [] argString){
        NewThread ob1 = new NewThread("1");
        NewThread ob2 = new NewThread("2");
        try{
            ob1.mySuspend();
            System.out.println("1 Suspended !!!");
            Thread.sleep(1000);
            ob1.myResume();
            System.out.println("1 Resumed !!!");
            ob2.mySuspend();
            System.out.println("1 Suspended !!!");
            Thread.sleep(1000);
            ob1.myResume();
            System.out.println("1 Resumed !!!");
        }
        catch (InterruptedException e){
            System.err.println("Interrupted !!!");
        }
        System.out.println("Main Thread Exited !!!");
    }
}
