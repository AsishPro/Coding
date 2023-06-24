import java.io.*;

public class buffer_reader
{

public static void main (String[] args) throws IOException

{

BufferedReader br = new BufferedReader (new InputStreamReader(System.in));

System.out.println ("Enter a character:");

char ch = (char) br.read();

System.out.println ("You entered: \"" + ch + "\"");

}

}