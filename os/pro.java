
class Semaphore {
    private int count;

    public Semaphore(int count) {
        this.count = count;
    }

    public synchronized void acquire() {
        while (count == 0) {
            try {
                wait();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        count--;
    }

    public synchronized void release() {
        count++;
        notify();
    }
}

class Producer implements Runnable {
    private int[] buffer;
    private Semaphore sem;
    private int index;

    public Producer(int[] buffer, Semaphore sem) {
        this.buffer = buffer;
        this.sem = sem;
        this.index = 0;
    }

    public void run() {
        for (int i = 0; i < 10; i++){
            sem.acquire();
            buffer[index] = i;
            index++;
            System.out.println("Produced " + i);
            sem.release();
        }
    }
}

class Consumer implements Runnable {
    private int[] buffer;
    private Semaphore sem;
    private int index;

    public Consumer(int[] buffer, Semaphore sem) {
        this.buffer = buffer;
        this.sem = sem;
        this.index = 0;
    }

    public void run() {
        while (true) {
            sem.acquire();
            if (index == buffer.length){
                sem.release();
                break;
            }
            int val = buffer[index];
            index++;
            System.out.println("Consumed " + val);
            sem.release();
        }
    }
}

class pro {
    public static void main(String[] args) {
        int[] buffer = new int[10];
        Semaphore semaphore = new Semaphore(3);

        Producer producer = new Producer(buffer, semaphore);
        Consumer consumer = new Consumer(buffer, semaphore);

        Thread producerThread = new Thread(producer);
        Thread consumerThread = new Thread(consumer);

        producerThread.start();
        consumerThread.start();

        try {
            producerThread.join();
            consumerThread.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}