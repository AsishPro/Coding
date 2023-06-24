package consumer;
import java.util.LinkedList;

class ProducerConsumer {
    private static final LinkedList<Integer> buffer = new LinkedList<>();
    private static final int MAX_SIZE = 10;

    public static void main(String[] args) {
        Thread producer = new Thread(new Producer());
        Thread consumer = new Thread(new Consumer());
        producer.start();
        consumer.start();
    }

    static class Producer implements Runnable {
        public void run() {
            while (true) {
                synchronized (buffer) {
                    while (buffer.size() == MAX_SIZE) {
                        try {
                            buffer.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                    int value = (int) (Math.random() * 100);
                    buffer.add(value);
                    System.out.println("Produced: " + value);
                    buffer.notify();
                }
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class Consumer implements Runnable {
        public void run() {
            while (true) {
                synchronized (buffer) {
                    while (buffer.isEmpty()) {
                        try {
                            buffer.wait();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                    int value = buffer.removeFirst();
                    System.out.println("Consumed: " + value);
                    buffer.notify();
                }
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
