class SuspendClass implements Runnable{
	Thread t;
	private boolean suspendFlag;
	SuspendClass(String name){
	t = new Thread(this, name);
	suspendFlag = false;
	t.start();
	}
	public void run(){
	System.out.println(t);
	try{
	     for(int i = 0; i < 10; i++) 
	     {
		System.out.print(t + " ");
		System.out.println(i);
		synchronized (this){
		while(suspendFlag){ wait();}
		}
		Thread.sleep(1000);
	     }
	}
	catch(InterruptedException e){}
	}
	public void mySuspend(){
		suspendFlag = true;
	}
	synchronized public void myResume(){
		suspendFlag = false;
		notify();
	}
}
public class Test{
	public static void main(String[] args){
	SuspendClass s1 = new SuspendClass("new 1");
	SuspendClass s2 = new SuspendClass("new 2");
	try{
	Thread.sleep(1000);
	s1.mySuspend();
	Thread.sleep(1000);
	s2.mySuspend();
	Thread.sleep(1000);
	s1.myResume();
	s2.myResume();
	}
	catch(InterruptedException e){
	System.out.println("Main Thread interrupted !!!");
	}
	}
}
