//Multiple Inheritance not supported by Java 
//1. Inheriting properties from Thread class
//2. Implementing Runnable interface
class A_1 extends Thread{
    public void run() {
        for(int i=0;i<=100;i++) {
            if(i%5==0) 
                System.out.println("Thread A value is : "+i);
        }
    }
}
class B_1 extends Thread{
    public void run() {
        for(int i=0;i<=100;i++) {
            if(i%3==0) 
                System.out.println("Thread B value is : "+i);
        }
    }
}
public class ThreadTest {

 

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        A_1 a = new A_1();//new born state
        B_1 b = new B_1();
        a.start();//runnable->running
        b.start();
        
    }
//main, a, b->schedule in a queue 
}