import java.io.*;
public class file {
    public static void main(String[] args) throws IOException{
       FileReader o1=new FileReader("file1.txt");
        char c=(char)o1.read();
        System.out.print(c);    
    }
}


// import java.io.*;
// public class file {
//     public static void main(String[] args) throws IOException{
//        FileInputStream o1=new FileInputStream("file1.txt");
//         BufferedInputStream o2=new BufferedInputStream(o1);
//         byte b[]=new byte[1];
//         o2.read(b);

//         System.out.print((char)b[0]);
//     }
// }






// import java.io.*;
// public class line {
// public static void main(String[] args)throws IOException{
// try{
// int i=0;
// BufferedReader bf=new BufferedReader(new FileReader(new
// File("file1.txt")));
// while(true){
// String s=bf.readLine();
// if(s==null)
// break;
// System.out.println(s);
// i++;
// }
// System.out.println("Number of lines: "+i);
// }
// catch(FileNotFoundException e){
// System.out.print("File not Found");
// }
// }
// }




// import java.io.*;
// public class file {
//     public static void main(String[] args) throws IOException{
//         FileInputStream f1=new FileInputStream("file1.txt");
//         // BufferedOutputStream bf=new BufferedOutputStream(f1);
//         int ch=1;
//         char s;
//         while(ch!=-1){
//             ch=f1.read();
//             if(ch==-1)
//             break;
//              s=(char)ch;
//             System.out.print(s);
//         }

//     }
// }





// import java.io.*;
// public class file {
//     public static void main(String[] args) throws IOException{
//         DataInputStream o1=new DataInputStream(System.in);
//         FileOutputStream f1=new FileOutputStream("file1.txt",true);
//         BufferedOutputStream bf=new BufferedOutputStream(f1,1);
//         // int ch=1;
//         String s="thesfsjlfnsfsfe";
//         // while(ch!=0){   
//         // ch=o1.read();
//         // if((char)ch=='@'){
//         //    break;
//         // }
//         // System.out.println((char)ch);
       
//         // }
//         bf.write( s.getBytes());


//     }
// }


// import java.io.*;
// public class file {
//     public static void main(String[] args) throws IOException{
//         DataInputStream o1=new DataInputStream(System.in);
//         FileOutputStream f1=new FileOutputStream("file1.txt", false);
//         char ch=(char)o1.read();
//         System.out.print(ch);
//         f1.write(ch);
//     }
// }
