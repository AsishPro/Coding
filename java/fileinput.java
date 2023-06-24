import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.*;
import java.util.Scanner;

class fileinput{
    public static void main(String[] args) throws IOException{
        // DataInputStream o1=new DataInputStream(System.in);
        // FileOutputStream fout=new FileOutputStream("file1.txt",true);
        // char ch;
        // while(true){
        //     ch=(char)o1.read();
        //     if(ch=='@')
        //     break;
        //     fout.write(ch);
        // }
        // fout.close();
        Scanner sc=new Scanner(new File("file1.txt"));
        while(sc.hasNext()){
            System.out.print(sc.nextLine());
        }

    }
}