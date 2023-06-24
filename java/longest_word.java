import java.util.Scanner;

import java.io.*;
class longest_word {
    public static void main(String[] args){
        File f=new File("srm.txt");
        try{
        Scanner sc=new Scanner(f);
        String lng="";
        while(sc.hasNext()){  
            String k=sc.next();
            System.out.print(k+" !");
            if(k.length()>lng.length())
                lng=k;
        }   
        System.out.print("Longest word :"+lng);
        }
        catch(FileNotFoundException e){
            System.out.print("File not found");
        }

    }
}
