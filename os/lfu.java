import java.util.*;

class lfu{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int n;
    System.out.print("Enter the Number of pages: ");
    n=sc.nextInt();
    System.out.print("Enter the size of frame list: ");
    int k=sc.nextInt();
    System.out.print("Enter the Sequence: ");
    int a[]=new int[n];
    for(int i=0;i<n;i++)
        a[i]=sc.nextInt();
    ArrayList<Integer> lt=new ArrayList<Integer>(k);
    int pg=0;
    for(int i=0;i<n;i++){
       if(lt.contains(a[i])) {
         lt.remove(Integer.valueOf(a[i]));
          lt.add(a[i]);
         //do nothing 
       }
       else if(lt.size()==k){
          pg++;
           lt.remove(0);
           lt.add(a[i]);
       }
       else{
        pg++;
        lt.add(a[i]);
       }
    }
    System.out.print(pg);
  }
}