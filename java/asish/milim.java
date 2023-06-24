import java.util.Scanner;

abstract class Customer {
    protected String name;
    protected String city;
    protected int age;
    protected String gender;
    protected double totalBillAmount;

    public Customer(String name, String city, int age, String gender, double totalBillAmount) {
        this.name = name;
        this.city = city;
        this.age = age;
        this.gender = gender;
        this.totalBillAmount = totalBillAmount;
    }

    public abstract double calculateDiscount();
}

class BasicCustomer extends Customer {
    public BasicCustomer(String name, String city, int age, String gender, double totalBillAmount) {
        super(name, city, age, gender, totalBillAmount);
    }

    @Override
    public double calculateDiscount() {
        double discount = 0;
        if (totalBillAmount >= 10000) {
            discount = 1000;
        } else if (totalBillAmount >= 7500) {
            discount = 500;
        } else if (totalBillAmount >= 5000) {
            discount = 250;
        } else if (totalBillAmount >= 1) {
            discount = 100;
        }
        return discount;
    }
}

class PremiumCustomer extends Customer {
    protected double subscriptionFee;

    public PremiumCustomer(String name, String city, int age, String gender, double totalBillAmount, double subscriptionFee) {
        super(name, city, age, gender, totalBillAmount);
        this.subscriptionFee = subscriptionFee;
    }

    @Override
    public double calculateDiscount() {
        double discount = 0;
        if (totalBillAmount >= 30000) {
            discount = 2000;
        } else if (totalBillAmount >= 20000) {
            discount = 1500;
        } else if (totalBillAmount >= 10000) {
            discount = 1000;
        } else if (totalBillAmount >= 7500) {
            discount = 700;
        } else if (totalBillAmount >= 5000) {
            discount = 400;
        } else if (totalBillAmount >= 1) {
            discount = 200;
        }
        return discount;
    }
}

public class milim {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String name = scanner.nextLine();
        String city = scanner.nextLine();
        int age = scanner.nextInt();
        scanner.nextLine();
        String gender = scanner.nextLine();
        double totalBillAmount = scanner.nextDouble();
        int isPremium = scanner.nextInt();

        Customer customer;
        double cashBackAmount;
        if (isPremium == 1) {
            double subscriptionFee = scanner.nextDouble();
            customer = new PremiumCustomer(name, city, age, gender, totalBillAmount, subscriptionFee);
            cashBackAmount = ((PremiumCustomer) customer).calculateDiscount();
        } else {
            customer = new BasicCustomer(name, city, age, gender, totalBillAmount);
            cashBackAmount = customer.calculateDiscount();
        }

        System.out.println("Name: " + customer.name);
        System.out.println("City: " + customer.city);
        System.out.println("Age: " + customer.age);
        System.out.println("Gender: " + customer.gender);
        System.out.println("Total Bill Amount: " + customer.totalBillAmount);

        if (isPremium == 1) {
            System.out.println("Subscription fee/month: " + ((PremiumCustomer) customer).subscriptionFee);
        }

        System.out.println("Discount: " + cashBackAmount);
    }
}