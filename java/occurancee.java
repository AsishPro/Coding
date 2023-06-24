import java.io.*;

public class occurancee {
    public static void main(String[] args)throws IOException{
    try{
    FileInputStream o1=new FileInputStream("srm.txt");
    BufferedReader req=new BufferedReader(new InputStreamReader(System.in));
        char s=req.readLine().charAt(0);
        int ch;
        int c=0;
        while(true){
          ch=o1.read();
          if(ch==-1)
          break;
          if(s==(char)ch)
            c+=1;      
        }
        System.out.print(c);
        o1.close();
        }
        catch(FileNotFoundException e){
            System.out.print("File not Found");
        }
    }
}
