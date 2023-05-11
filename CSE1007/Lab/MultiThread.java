class a1 extends Thread {
    int max = 99;
    int min = 0;
    public void run() {
        for (int i = 0; i < 10; i++) {
            int rand = (int)((Math.random() * (max - min)) + min);
            try {
                suspend();
                sleep(500);
            } catch (Exception e) {}
        }
    }
}

class a2 extends Thread {
    public void run() {
        for (int i = 0; i < 10; i++) {
            int rand = (int)Math.random();
            try {
                suspend();
                sleep(500);
            } catch (Exception e) {}
        }
    }
}

public class MultiThread {

    public static void main(String[] args) {
        a1 a = new a1();
        a2 b = new a2();
        a.start();
        b.start();
    }

}
