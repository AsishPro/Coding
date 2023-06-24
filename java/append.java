import java.io.*;
class append{
    public static void main(String[] args) throws IOException{
        FileOutputStream fout=new FileOutputStream("file1.txt",true);
        String str="Embark on the avenues of excellence with SRM University-AP! Believing in the power of education to transform lives, our interdisciplinary research-oriented undergraduate, postgraduate, and doctoral programmes ensure global exposure and entrepreneurial experience to our students. We are a thriving intellectual community prepared for a dynamic world.";
        for(int i=0;i<str.length();i++){
            fout.write((char)str.charAt(i));
        }
        fout.close();
        // //or we can write directly using filewriter class
        // FileWriter o1=new FileWriter("srm.txt",true);
        // o1.write(str);
        // o1.close();
    }
}