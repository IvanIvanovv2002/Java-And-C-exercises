class SharedResource {
    private int data;
    private boolean isDataAvailable = false;

    public  void produce(int newData) throws InterruptedException {

        synchronized (this) {
            if (isDataAvailable) { wait(); }
            data = newData;
            System.out.println("Produced: " + data);
            isDataAvailable = true;
            notify();
        }

    }
    public  void consume() throws InterruptedException {

        synchronized (this) {
            if (!isDataAvailable) { wait(); }
            System.out.println("Consumed: " + data);
            isDataAvailable = false;
            notify();
        }
    }
}

public class SharedResourcesMultiThreading {
    public static void main(String[] args) {
        SharedResource sharedResource = new SharedResource();

        // Producer thread
        Thread producerThread = new Thread(() -> {
            for (int i = 1; i <= 5; i++) {
                try {
                    sharedResource.produce(i);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                try {
                    Thread.sleep(1000); // Simulate some processing time
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        // Consumer thread
        Thread consumerThread = new Thread(() -> {
            for (int i = 0; i < 5; i++) {
                try {
                    sharedResource.consume();
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        producerThread.start();
        consumerThread.start();
    }
}
