import java.io.*;
import java.util.*;

public class longesst {
    public static String find(File f) throws IOException {

      FileReader fr=new FileReader(f);
      BufferedReader br=new BufferedReader(fr);
      String longest="";
      int word=br.read();
      ArrayList<String> arr = new ArrayList<>();
      int k=0;
      while (word!=-1){
        char c=(char)word;
        if(c == ' '){
            arr.add(longest);
            k++;
            longest="";
        }
        else if(c == ','){

        }
        else{
            longest+=(char)word;
       }
       word=br.read();
    }
    longest="";
    for(int i=0;i<k;i++)
       if(arr.get(i).length()>longest.length())
           longest=arr.get(i);
    System.out.print(longest);

    return longest;
}

public static void main(String [ ] args) throws FileNotFoundException 
            {
                File f1=new File("srm.txt");
                try{
                    find(f1);
                }
                catch(IOException e)
                {
                    System.out.println(e);
                }
           }
}