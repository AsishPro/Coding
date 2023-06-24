import java.io.*;

public class line {
    public static void main(String[] args)throws IOException{
    try{
        int i=0;
    BufferedReader bf=new BufferedReader(new FileReader(new File("file1.txt")));
        while(true){
            String s=bf.readLine();
            if(s==null)
            break;
            System.out.println(s);
            i++;
        }  
        System.out.println("Number of lines: "+i);
        }
        catch(FileNotFoundException e){
            System.out.print("File not Found");
        }
    }
}
