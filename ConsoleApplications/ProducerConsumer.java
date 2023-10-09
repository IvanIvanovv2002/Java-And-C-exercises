import java.util.Random;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.BlockingQueue;

public class ProducerConsumer {

    /*
        A simple producer-consumer design pattern in multithreading programming with BlockingQueue
        in order to ease the work, instaed of using synchronous methods
     */

   static BlockingQueue<Integer> blockingQueue = new ArrayBlockingQueue<>(10);

    static class ProducerThread extends Thread {

        @Override
        public void run() {
            produce();
        }
    }
    static class ConsumerThread extends Thread {

        @Override
        public void run() {
            try {
                consume();
            } catch (InterruptedException ignored) {}
        }
    }
    static void consume() throws InterruptedException {

        while (true) {
            Random random = new Random();
            if (random.nextInt(10) == 0) {
                Integer takenValue = blockingQueue.take();
                Thread.sleep(2000);
                System.out.println("Value taken: " + takenValue + " queue size: " + blockingQueue.size());
            }
        }
    }
    static void produce() {
        while (true) {
            Random random = new Random();
            blockingQueue.offer(random.nextInt(100));
        }
    }
    public static void main(String[] args) throws InterruptedException {

        ProducerThread producerThread = new ProducerThread();
        ConsumerThread consumerThread = new ConsumerThread();

        producerThread.start();
        consumerThread.start();

        producerThread.join();
        consumerThread.join();
    }
}