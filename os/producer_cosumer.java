import java.util.concurrent.Semaphore;
import java.util.LinkedList;

class producer_consumer {
    // Number of items to produce and consume
    static final int numItems = 10;

    // Buffer size
    static final int bufferSize = 5;

    // Buffer
    static LinkedList<Integer> buffer = new LinkedList<>();

    // Semaphore for empty and full slots in the buffer
    static Semaphore empty = new Semaphore(bufferSize);
    static Semaphore full = new Semaphore(0);

    // Producer function
    static class Producer implements Runnable {
        int id;

        Producer(int id) {
            this.id = id;
        }

        public void run() {
            try {
                for (int i = 0; i < numItems; i++) {
                    // Wait for empty slot
                    empty.acquire();

                    // Produce item
                    int item = i + 1;

                    // Acquire lock on buffer
                    synchronized (buffer) {
                        // Add item to buffer
                        buffer.add(item);

                        System.out.println("Producer " + id + " produced item " + item);

                        // Notify consumer
                        buffer.notifyAll();
                    }

                    // Release lock on buffer

                    // Signal full slot
                    full.release();
                }

                System.out.println("Producer " + id + " finished producing items");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    // Consumer function
    static class Consumer implements Runnable {
        int id;

        Consumer(int id) {
            this.id = id;
        }

        public void run() {
            try {
                for (int i = 0; i < numItems; i++) {
                    // Wait for full slot
                    full.acquire();

                    // Acquire lock on buffer
                    synchronized (buffer) {
                        // Wait for item to be available in buffer
                        while (buffer.isEmpty()) {
                            buffer.wait();
                        }

                        // Consume item
                        int item = buffer.remove();

                        System.out.println("Consumer " + id + " consumed item " + item);

                        // Notify producer
                        buffer.notifyAll();
                    }

                    // Release lock on buffer

                    // Signal empty slot
                    empty.release();
                }

                System.out.println("Consumer " + id + " finished consuming items");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        // Create producer and consumer threads
        Thread producerThread1 = new Thread(new Producer(1));
        Thread producerThread2 = new Thread(new Producer(2));
        Thread consumerThread1 = new Thread(new Consumer(1));
        Thread consumerThread2 = new Thread(new Consumer(2));

        // Start threads
        producerThread1.start();
        producerThread2.start();
        consumerThread1.start();
       consumerThread2.start();

        // Wait for threads to finish
        try {
            producerThread1.join();
            producerThread2.join();
            consumerThread1.join();
            consumerThread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}