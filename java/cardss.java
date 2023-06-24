import java.util.*;


class cardss{
    public static void main(String[] args) {
		Scanner sc = new Scanner(System. in);
		int n= sc. nextInt();
		int k= sc. nextInt();
        String[] suit = new String[] {"Spades", "Hearts", "Diamonds", "Clubs" };
        String[] rank = new String[] {"Ace", "2", "3", "4","5", "6", "7", "8", "9", "10","Jack", "Queen", "King"};
        
        List<String> deck = new ArrayList<String>();
        for (int i = 0; i < suit.length; i++)
            for (int j = 0; j < rank.length; j++)
                deck.add(rank[j] + " of " + suit[i]);

        Collections.shuffle(deck, new Random(0));
    
        if (n*k>deck.size()){
            System.out.println("Not enough cards.");
            return;
        }
        for (int i = 0; i < n; i++)
            System.out.println(dealHand(deck, k));
    }
  
    public static String dealHand(List<String> deck, int n) {
        int size=deck.size();
        List<String> handview=deck.subList(size-n, size);
        String s=handview.get(0);
        handview.clear();
        return s;
    }
}