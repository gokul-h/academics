//Multiple Inheritance not supported by Java 

 

class A_2 implements Runnable{
    public void run() {
        for(int i=0;i<=100;i++) {
            if(i%5==0) 
                System.out.println("Thread A value is : "+i);
        }
    }
}
class B_2 implements Runnable{
    public void run() {
        for(int i=0;i<=100;i++) {
            if(i%3==0) 
                System.out.println("Thread B value is : "+i);
        }
    }
}
public class ThreadTest1 {

 

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        A_2 a = new A_2();//new born state
        Thread t1 = new Thread(a);
        B_2 b = new B_2();
        Thread t2 = new Thread(b);
        t1.start();//runnable->running
        t2.start();
    }

 

}