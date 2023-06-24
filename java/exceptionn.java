import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*; 
import java.lang.Exception;
import java.util.concurrent.ExecutionException;
class test{
    static void validate() throws Exception{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int a=Integer.parseInt(reader.readLine());
        int b=Integer.parseInt(reader.readLine());
        int z=a/b;
        throw new Exception();
        // System.out.print("good");
    }
}
class exceptionn {
   public static void main(String[] args){
      try{
        test.validate();
      }
      catch(Exception o){
        System.out.print(o);
      }
   }
}
