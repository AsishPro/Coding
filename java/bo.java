import java.util.*;
import java.util.concurrent.TimeUnit;
import java.text.SimpleDateFormat;  

class ItemType{
     
    String name;
    Double deposit;
    Double cost;
    
    ItemType(String name, Double deposit, Double costPerDay) {
        this.name = name;
        this.deposit = deposit;
        this.cost = costPerDay;
    }
    void print(){
        System.out.println(this.name);
        System.out.printf("%.1f\n",deposit);
        System.out.printf("%.1f\n",this.cost);
    }
    
    public Double getCostPerDay() {
        return cost;
    }
}

class ItemTypeBO {
    
    Double calculateCost(double diff,ItemType type) {
        return diff * type.getCostPerDay();
    }
    
    double date_diff(String s,String e){
        try {
            SimpleDateFormat sdf = new SimpleDateFormat("dd/mm/yyyy");
                Date start = sdf.parse(s);
                Date end = sdf.parse(e);
                long timeDiff = Math.abs(start.getTime() - end.getTime());
                long daysDiff = TimeUnit.DAYS.convert(timeDiff, TimeUnit.MILLISECONDS);
                return (double)daysDiff;
            }
            catch(Exception en){
                System.out.print("Error");
            }
            return 0;
    }
}
class bo{
      public static void main(String[] args){

        Scanner sc=new Scanner(System.in);
          String name=sc.next();
          double deposit=sc.nextDouble();
          double cost=sc.nextDouble();
          String s=sc.next();
          String e=sc.next();
          ItemTypeBO o2=new ItemTypeBO();
          double diff=o2.date_diff(s, e);
          ItemType o1=new ItemType(name,deposit,cost);
        
          double k=o2.calculateCost(diff, o1);
          System.out.printf("%.1f",k);
      }
      
}