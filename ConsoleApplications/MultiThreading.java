import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MultiThreading {

    // the time difference between using different intrinsic locks vs synchronizes method
    // is roughly 60-70% advantageous towards  -> different intrinsic locks <-
    List<Integer> l1 = new ArrayList<>();
    List<Integer> l2 = new ArrayList<>();

    final Object lock1 = new Object();
    final Object lock2 = new Object();
    public void stage1() throws InterruptedException {
        synchronized (lock1) {
            Thread.sleep(1);
            l1.add(new Random().nextInt(100));
        }
    }

    public void stage2() throws InterruptedException {
        synchronized (lock2) {
            Thread.sleep(1);
            l2.add(new Random().nextInt(100));
        }
    }

    public void work() throws InterruptedException {
        stage1();
        stage2();
    }

    public static void main(String[] args) throws InterruptedException {
        MultiThreading multiThreading = new MultiThreading();
        long time1 = System.currentTimeMillis();
        multiThreading.doWork();
        long time2 = System.currentTimeMillis();
        System.out.println(time2 - time1);
    }

    public void doWork() throws InterruptedException {

        Thread t1 = new Thread(() -> {
            for (int i = 1; i <= 1000; i++) {
                try {
                    work();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 1; i <= 1000; i++) {
                try {
                    work();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.printf("List 1 -> %d , List 2 -> %d\n",l1.size(),l2.size());
    }

}