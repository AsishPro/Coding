import java.util.*;
import java.lang.Exception;

public class Nested {
    public static void main(String[] args){
        try{
            int a=1;
            int b=2;
            int z=a/2;
            try{
                int arr[]={1,2,34};
                System.out.print(arr[6]);
            }
            catch(Exception k){
                System.out.print(k);
            }
        }
        catch(Exception e){
            System.out.print(e);
        }
    }
}
