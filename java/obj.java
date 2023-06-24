import java.util.ArrayList;
class test{
    int a;
    char c;
    boolean t;
    int arr[]=new int[5];
    test(){}
    test(int a,char c,boolean t,int arr[]){
            this.a=a;
            this.c=c;
            this.t=t;
            this.arr=arr;
    }
    void print(){
        System.out.println(a);
        System.out.println(c);
        System.out.println(t);
        for(int i=0;i<arr.length;i++)
            System.out.print(arr[i]+" ");
    }
}

public class obj {
    public static void main(String[] args){
        
        int a[]={5,6,7,8,9};
        test o1=new test(5, 'a', true, a);

        ArrayList<test> o = new ArrayList<test>();
        o.add(o1);
        test k[]=o.toArray(new test[o.size()]);
        k[0].print();

    }
    
}
