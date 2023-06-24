import java.util.concurrent.Semaphore;

public class ProducerConsumer {
    private static final int BUFFER_SIZE = 10;
    private static final Semaphore empty = new Semaphore(BUFFER_SIZE);
    private static final Semaphore full = new Semaphore(0);
    private static final Semaphore mutex = new Semaphore(1);
    private static final int[] buffer = new int[BUFFER_SIZE];
    private static int in = 0, out = 0;

    public static void main(String[] args) {
        Thread producer = new Thread(new Producer());
        Thread consumer = new Thread(new Consumer());
        producer.start();
        consumer.start();
    }

    static class Producer implements Runnable {
        public void run() {
            while (true) {
                try {
                    empty.acquire(); // acquire an empty slot in the buffer
                    mutex.acquire(); // acquire the lock on the buffer
                    buffer[in] = 1; // produce an item
                    System.out.println("Produced item " + in);
                    in = (in + 1) % BUFFER_SIZE; // update the index of the next empty slot
                    mutex.release(); // release the lock on the buffer
                    full.release(); // signal that a slot has been filled
                    Thread.sleep(1000); // simulate some processing time
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class Consumer implements Runnable {
        public void run() {
            while (true) {
                try {
                    full.acquire(); // acquire a filled slot in the buffer
                    mutex.acquire(); // acquire the lock on the buffer
                    int item = buffer[out]; // consume an item
                    System.out.println("Consumed item " + out);
                    out = (out + 1) % BUFFER_SIZE; // update the index of the next filled slot
                    mutex.release(); // release the lock on the buffer
                    empty.release(); // signal that a slot has been emptied
                    Thread.sleep(1000); // simulate some processing time
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}