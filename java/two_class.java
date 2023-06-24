class room{
    float b;
    float l;
    static float h;
    void getdata(float a,float b,float c){
        l=a;
        h=c;
        this.b=b;
    }
}

public class two_class {
    public static void main(String[] Args){
       //float area;
       room r1= new room();
       r1.getdata(6,7,8);
       System.out.println(room.h);
       room r2= new room();
       r2.getdata(10,11,12);
       System.out.println(room.h);
    }
}
