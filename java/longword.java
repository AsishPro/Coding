import java.io.*;

class longword {

    public static void main(String[] args) throws IOException {
        // Open the file for reading
        File file = new File("srm.txt");
        BufferedReader reader = new BufferedReader(new FileReader(file));

        // Find the longest word in the file
        String longestWord = "";
        String line;
        while ((line = reader.readLine()) != null) {
            String[] words = line.split("[\\s\\.\\,\\!\\?]+");
            for (String word : words) {
                if (word.length() > longestWord.length()) {
                    longestWord = word;
                }
            }
        }

        // Print the longest word
        System.out.println("The longest word in the file is: " + longestWord);

        // Close the reader
        reader.close();
    }
}