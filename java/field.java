import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.*;
class field{
    public static void writeToFile() throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter("myFile.txt"));
        bw.write("Test");
        bw.close();
    }
public static void main(String[] args) {
    writeToFile();
}
}